var geos = WScript.CreateObject("geos.geos");

var results = "";

function assert(result, message) {
	if (result == false) {
		WScript.Echo("assert: " + message);
		results += "x";
	} else {
		results += "o";
	}
};

function assertEqual(expected, result, message) {
	if (expected != result) {
		WScript.Echo("assertEqual: " + message + "\n" + "expected:" + "\t" + expected + "\n" + "result:" + "\t" + result);
		results += "x";
	} else {
		results += "o";
	}
};

function report() {
	if (results.indexOf("x", 0) >= 0) {
		WScript.Echo("Failed! - " + results);
	} else {
		WScript.Echo("Succeeded! - " + results);
	}
	results = "";
};

function TestCoordinateSequence() {
};

TestCoordinateSequence.prototype.testCreate = function() {
	WScript.Echo("testCreate");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3);
//	assertEqual("ICoordinateSequence", typeof(cs), "typeof(cs)"); // TODO: always "object"
	
	report();
};

TestCoordinateSequence.prototype.testSize = function() {
	WScript.Echo("testSize");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(7, 2);
	assertEqual(7, cs.getSize(), "cs.getSize()");
	
	report();
};

TestCoordinateSequence.prototype.testGetterSetter = function() {
	WScript.Echo("testGetterSetter");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3);
	cs.setX(0, 3);
	cs.setY(0, 4);
	cs.setZ(0, 5);
	cs.setX(1, 6);
	cs.setY(1, 7);
	cs.setZ(1, 8);
	assertEqual(3, cs.getX(0), "cs.getX(0)");
	assertEqual(4, cs.getY(0), "cs.getY(0)");
	assertEqual(5, cs.getZ(0), "cs.getZ(0)");
	assertEqual(6, cs.getX(1), "cs.getX(1)");
	assertEqual(7, cs.getY(1), "cs.getY(1)");
	assertEqual(8, cs.getZ(1), "cs.getZ(1)");
	
	report();
};

TestCoordinateSequence.prototype.testIndexOutOfBounds = function() {
	WScript.Echo("testIndexOutOfBounds");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3);
	cs.setX(2, 6);
	cs.setY(2, 6);
	cs.setZ(2, 6);
	
	report();
};

TestCoordinateSequence.prototype.testOrdinate = function() {
	WScript.Echo("testOrdinate");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3);
	cs.setOrdinate(0, 0, 2);
	cs.setOrdinate(0, 1, 3);
	cs.setOrdinate(0, 2, 4);
	
	assertEqual(2, cs.getOrdinate(0, 0), "cs.getOrdinate(0, 0)");
	assertEqual(3, cs.getOrdinate(0, 1), "cs.getOrdinate(0, 1)");
	assertEqual(4, cs.getOrdinate(0, 2), "cs.getOrdinate(0, 2)");
	
	report();
};

TestCoordinateSequence.prototype.testClone = function() {
	WScript.Echo("testClone");
	
	var cs1 = geos.CoordinateSequence.new_CoordinateSequence(1, 3);
	cs1.setX(0, 2);
	cs1.setY(0, 3);
	cs1.setZ(0, 4);
	
	var cs2 = cs1.clone();
	
//	assert(cs1 = cs2); ' TODO:
	assertEqual(2, cs2.getX(0), "cs2.getX(0)");
	assertEqual(3, cs2.getY(0), "cs2.getY(0)");
	assertEqual(4, cs2.getZ(0), "cs2.getZ(0)");
	
	cs2.setX(0, 5);
	cs2.setY(0, 6);
	cs2.setZ(0, 7);
	
	assertEqual(2, cs1.getX(0), "cs1.getX(0)");
	assertEqual(3, cs1.getY(0), "cs1.getY(0)");
	assertEqual(4, cs1.getZ(0), "cs1.getZ(0)");
	
	assertEqual(5, cs2.getX(0), "cs2.getX(0)");
	assertEqual(6, cs2.getY(0), "cs2.getY(0)");
	assertEqual(7, cs2.getZ(0), "cs2.getZ(0)");
	
	report();
};

TestCoordinateSequence.prototype.testDimensions = function() {
	WScript.Echo("testDimensions");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3);
	assertEqual(3, cs.getDimensions(), "cs.getDimensions()");
	
	report();
};

var test = new TestCoordinateSequence();
test.testCreate();
test.testSize();
test.testGetterSetter();
//test.testIndexOutOfBounds();
test.testOrdinate();
test.testClone();
test.testDimensions();
