#ifndef CAPTUREOBJECTUTIL_H
#define CAPTUREOBJECTUTIL_H

#include <osg/Vec3>
#include <osg/Matrix>
#include <osg/NodeVisitor>
#include <osg/Transform>

#include "Marker.h"
#include "Marcos.h"

////////////////////////////////////////
// The following class is from https://www.movesinstitute.org/Sullivan/OSGTutorials/osgGetWorldCoords.htm
////////////////////////////////////////
// Visitor to return the world coordinates of a node.
// It traverses from the starting node to the parent.
// The first time it reaches a root node, it stores the world coordinates of 
// the node it started from.  The world coordinates are found by concatenating all 
// the matrix transforms found on the path from the start node to the root node.

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


namespace CaptureObjectUtil
{
	bool orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon);

	osg::Matrix* makeLocalToGlobalMatrix(osg::Vec3 origin, osg::Vec3 x, osg::Vec3 y);

	osg::Vec3 quaternionToEuler(osg::Quat q);

	osg::Matrixd* getWorldCoords( osg::Node* node);
};

#endif
