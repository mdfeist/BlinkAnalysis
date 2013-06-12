#pragma once
#include "stdafx.h"
#include "AppData.h"

#include <vector>
#include <osg/Vec3>


class EyeCalibration {
private:
	class CalibrationPoint {
	private:
		int _x, _y;
		osg::Vec3 _ray;
	public:
		CalibrationPoint() {}
		CalibrationPoint(int x, int y, osg::Vec3 ray) {
			_x = x;
			_y = y;
			_ray = ray;
		}

		osg::Vec3& ray() { return _ray; }
		int& x() { return _x; }
		int& y() { return _y; }

		bool equal(const CalibrationPoint& rhs) {
			return _x==rhs._x && _y==rhs._y;
		}
		
		/** Multiply by scalar. */
        inline const CalibrationPoint operator * (float rhs) const
        {
            return CalibrationPoint(_x*rhs, _y*rhs, _ray*rhs);
        }

        /** Unary multiply by scalar. */
        inline CalibrationPoint& operator *= (float rhs)
        {
            _x*=rhs;
            _y*=rhs;
            _ray*=rhs;
            return *this;
        }

        /** Divide by scalar. */
        inline const CalibrationPoint operator / (float rhs) const
        {
            return CalibrationPoint(_x/rhs, _y/rhs, _ray/rhs);
        }

        /** Unary divide by scalar. */
        inline CalibrationPoint& operator /= (float rhs)
        {
            _x/=rhs;
            _y/=rhs;
            _ray/=rhs;
            return *this;
        }

        /** Binary vector add. */
        inline const CalibrationPoint operator + (const CalibrationPoint& rhs) const
        {
            return CalibrationPoint(_x+rhs._x, _y+rhs._y, _ray+rhs._ray);
        }

		 /** Binary vector add. */
        inline CalibrationPoint& operator += (const CalibrationPoint& rhs)
        {
            _x+=rhs._x;
			_y+=rhs._y;
			_ray+=rhs._ray;
			return *this;
        }

        /** Binary vector subtract. */
        inline const CalibrationPoint operator - (CalibrationPoint& rhs) const
        {
            return CalibrationPoint(_x-rhs._x, _y-rhs._y, _ray-rhs._ray);
        }

		 /** Binary vector subtract. */
        inline CalibrationPoint& operator -= (const CalibrationPoint& rhs)
        {
            _x-=rhs._x;
			_y-=rhs._y;
			_ray-=rhs._ray;
			return *this;
        }

        /** Negation operator. Returns the negative of the Vec3f. */
        inline const CalibrationPoint operator - () const
        {
            return CalibrationPoint(-_x, -_y, -_ray);
        }
	};

	class Segment {
	private:
		CalibrationPoint _p1, _p2;
	public:
		Segment() {}
		Segment(CalibrationPoint from, CalibrationPoint to) {
			_p1 = from;
			_p2 = to;
		}

		CalibrationPoint& p1() { return _p1; }
		CalibrationPoint& p2() { return _p2; }

		int x1() { return _p1.x(); }
		int y1() { return _p1.y(); }
		int x2() { return _p2.x(); }
		int y2() { return _p2.y(); }
	};

	// Typedef an STL vector of vertices which are used to represent
	// a polygon/contour and a series of triangles.
	typedef std::vector< CalibrationPoint > CalibrationPointVector;
	typedef std::vector< Segment > SegmentVector;

	int rbHeadId;
	int rbViewingObjectId;
	// Used to store the calibrated eye vectors
	float *eyeVectorArray;
	unsigned long viewingWidth;
	unsigned long viewingHeight;
	unsigned long viewingMargin;

	char* getNameById(int id);

	CalibrationPointVector calibrationPoints;

	int center_x, center_y;

	// triangulate a contour/polygon, places results in STL vector as series of triangles.
	bool triangulate(CalibrationPointVector &contour, CalibrationPointVector &result);
	// compute area of a contour/polygon
	float area(CalibrationPointVector &contour);
	// decide if point Px/Py is inside triangle defined by
	// (Ax,Ay) (Bx,By) (Cx,Cy)
	bool insideTriangle(CalibrationPoint A, CalibrationPoint B, CalibrationPoint C, CalibrationPoint P);
	bool snip(CalibrationPointVector &contour,int u,int v,int w,int n,int *V);

	// Convex Hull
	SegmentVector calculateConvexHull(CalibrationPointVector processingPoints);
	bool boundingPointsOfHull(SegmentVector &contour, CalibrationPointVector &result);
	bool isInCircumCircle(CalibrationPoint &point, CalibrationPointVector &traingle);

	bool sort(CalibrationPointVector &points, int center_x, int center_y);

	int getLineIntersection(CalibrationPoint A, CalibrationPoint B, CalibrationPoint C, CalibrationPoint D);
	bool isEdge(CalibrationPointVector processingPoints, Segment edge);
	int isLeft(Segment segment, CalibrationPoint r);
	bool isLess(CalibrationPoint a, CalibrationPoint b, int center_x, int center_y);
	SegmentVector getEdges(CalibrationPointVector processingPoints);
	CalibrationPoint getClosestPoint(CalibrationPoint a, CalibrationPoint b, CalibrationPoint point, bool segmentClamp);

	struct ComparePoints : std::binary_function<CalibrationPoint, CalibrationPoint, bool> {
		ComparePoints(EyeCalibration * cal, int x, int y) : _cal(cal), _x(x), _y(y) {}
		bool operator() (const CalibrationPoint& a, const CalibrationPoint& b) const {
			return _cal->isLess(a, b, _x, _y);
		}

		EyeCalibration * _cal;
		int _x, _y;
	};

	struct ComparePointsDistanceFrom : std::binary_function<CalibrationPoint, CalibrationPoint, bool> {
		ComparePointsDistanceFrom(EyeCalibration * cal, CalibrationPoint point) : _cal(cal), _point(point) {}
		bool operator() (CalibrationPoint a, CalibrationPoint b) {
			float distanceA = (_point.x()-a.x())*(_point.x()-a.x()) + (_point.y()-a.y())*(_point.y()-a.y());
			float distanceB = (_point.x()-b.x())*(_point.x()-b.x()) + (_point.y()-b.y())*(_point.y()-b.y());

			if (distanceA > distanceB)
				return true;

			return false;
		}

		EyeCalibration * _cal;
		CalibrationPoint _point;
	};

public:
	EyeCalibration(void);
	~EyeCalibration(void);
	
	void setHeadId(int id) { this->rbHeadId = id; }
	int getHeadId() { return this->rbHeadId; }
	char* getHeadName() { return getNameById(this->rbHeadId); }

	void setViewingObjectId(int id) { this->rbViewingObjectId = id; }
	int getViewingObjectId() { return this->rbViewingObjectId; }
	char* getViewingObjectName() { return getNameById(this->rbViewingObjectId); }

	bool addPoint();
	bool calibrate();

	void createTestData();

	void saveRayMap();
};