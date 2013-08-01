#ifndef CAPTUREOBJECTUTIL_H
#define CAPTUREOBJECTUTIL_H

#include <osg/Vec3>
#include <osg/Matrix>
#include <osg/NodeVisitor>
#include <osg/Transform>

#include "Marker.h"
#include "Marcos.h"


enum ObjectType {
	OBJ_PLANE,
	OBJ_BOX,
	OBJ_CYLINDER,
	OBJ_CUSTOM,
	OBJ_INVALID
};


/**
 * The following class is from https://www.movesinstitute.org/Sullivan/OSGTutorials/osgGetWorldCoords.htm \n
 *  \n
 * Visitor to return the world coordinates of a node. \n
 * It traverses from the starting node to the parent. \n
 * The first time it reaches a root node, it stores the world coordinates of  \n
 * the node it started from.  The world coordinates are found by concatenating all  \n
 * the matrix transforms found on the path from the start node to the root node. \n
 */
class getWorldCoordOfNodeVisitor : public osg::NodeVisitor 
{
public:
   getWorldCoordOfNodeVisitor():
      osg::NodeVisitor(NodeVisitor::TRAVERSE_PARENTS), done(false)
      {
         wcMatrix= new osg::Matrixd();
      }
      virtual void apply(osg::Node &node)
      {
         if (!done)
         {
            if ( 0 == node.getNumParents() ) // no parents
            {
               wcMatrix->set( osg::computeLocalToWorld(this->getNodePath()) );
               done = true;
            }
            traverse(node);
         }
      }
      osg::Matrixd* giveUpDaMat() 
      {
         return wcMatrix;
      }
private:
   bool done;
   osg::Matrix* wcMatrix;
};


/**
 * Helper methods for capture object creation/manipulation
 */
namespace CaptureObjectUtil
{
	osg::Matrix* makeLocalToGlobalMatrix(osg::Vec3 origin, osg::Vec3 x, osg::Vec3 y);

	osg::Vec3 quaternionToEuler(osg::Quat q);

	osg::Matrixd* getWorldCoords( osg::Node* node);

	char* objectTypeToString(ObjectType t);

	std::string* floatToString(double d);
};

#endif
