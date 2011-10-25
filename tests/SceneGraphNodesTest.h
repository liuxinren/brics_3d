/**
 * @file 
 * SceneGraphNodesTest.h
 *
 * @date: Oct 20, 2011
 * @author: sblume
 */

#ifndef SCENEGRAPHNODESTEST_H_
#define SCENEGRAPHNODESTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "core/HomogeneousMatrix44.h"
#include "worldModel/sceneGraph/Node.h"
#include "worldModel/sceneGraph/Group.h"
#include "worldModel/sceneGraph/Transform.h"
#include "worldModel/sceneGraph/INodeVisitor.h"

namespace unitTests {

using namespace BRICS_3D;
using namespace Eigen;
using namespace std;
using namespace BRICS_3D::RSG;
using std::cout;
using std::endl;

/*
 * Example how to implement custom visitors.
 */
class IdCollector : public INodeVisitor {
public:
	void visit(Node* node){
		cout << "Node ID  = " << node->getId() << endl;
		collectedIDs.push_back(node->getId());
	};
	void visit(Group* node){
		cout << "Group ID = " << node->getId() << endl;
		collectedIDs.push_back(node->getId());
	};

	std::vector<unsigned int> collectedIDs;
};

class SceneGraphNodesTest : public CPPUNIT_NS::TestFixture {

	CPPUNIT_TEST_SUITE( SceneGraphNodesTest );
	CPPUNIT_TEST( testNode );
	CPPUNIT_TEST( testGroup );
	CPPUNIT_TEST( testTransform );
	CPPUNIT_TEST( testSimpleGraph );
	CPPUNIT_TEST( testOwnership );
	CPPUNIT_TEST( testSimpleVisitor );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testNode();
	void testGroup();
	void testTransform();
	void testOwnership();
	void testSimpleGraph();
	void testSimpleVisitor();

};

}

#endif /* SCENEGRAPHNODESTEST_H_ */

/* EOF */
