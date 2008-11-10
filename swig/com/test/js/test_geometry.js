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

function TestGeometry() {
};

TestGeometry.prototype.testCreatePoint = function() {
	WScript.Echo("testCreatePoint");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 3);
	cs.setX(0, 7);
	cs.setY(0, 8);
	cs.setZ(0, 9);
	
	var geom = geos.createPoint(cs);
//		assertEqual("IPoint", typeof(geom), "typeof(geom)"); // TODO: always "object"
	assertEqual("Point", geom.geomType(), "geom.geomType()");
	assertEqual(geos.GEOS_POINT, geom.typeId(), "geom.typeId()");
	
	assertEqual(false, geom.isEmpty(), "geom.isEmpty()");
	assertEqual(true, geom.isValid(), "geom.isValid()");
	assertEqual(true, geom.isSimple(), "geom.isSimple()");
	assertEqual(false, geom.isRing(), "geom.isRing()");
	assertEqual(true, geom.hasZ(), "geom.hasZ()");
	
	assertEqual(1, geom.getNumGeometries(), "geom.getNumGeometries()");
	
	var coords = geom.getCoordSeq();
//		assertEqual("ICoordinateSequence", typeof(coords), "typeof(coords)"); // TODO: always "object"
	assertEqual(7, coords.getX(0), "coords.getX(0)");
	assertEqual(8, coords.getY(0), "coords.getY(0)");
	assertEqual(9, coords.getZ(0), "coords.getZ(0)");
	
	assertEqual(0, geom.area(), "geom.area()");
	assertEqual(0, geom.length(), "geom.length()");
	
	report();
};

TestGeometry.prototype.testCreatePointIllegal = function() {
	WScript.Echo("testCreatePointIllegal");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(0, 0);
	var geom = geos.createPoint(cs);
	
	report();
};

TestGeometry.prototype.testCreateLineString = function() {
	WScript.Echo("testCreateLineString");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(2, 3);
	cs.setX(0, 7);
	cs.setY(0, 8);
	cs.setZ(0, 9);
	cs.setX(1, 3);
	cs.setY(1, 3);
	cs.setZ(1, 3);
	
	var geom = geos.createLineString(cs);
//	assertEqual("ILineString", typeof(geom), "typeof(geom)"); // TODO: always "object"
	assertEqual("LineString", geom.geomType(), "geom.geomType()");
	assertEqual(geos.GEOS_LINESTRING, geom.typeId(), "geom.typeId()");
	
	assertEqual(false, geom.isEmpty(), "geom.isEmpty()");
	assertEqual(true, geom.isValid(), "geom.isValid()");
	assertEqual(true, geom.isSimple(), "geom.isSimple()");
	assertEqual(false, geom.isRing(), "geom.isRing()");
	assertEqual(true, geom.hasZ(), "geom.hasZ()");
	
	assertEqual(1, geom.getNumGeometries(), "geom.getNumGeometries()");
	
	var coords = geom.getCoordSeq();
//	assertEqual("ICoordinateSequence", typeof(coords), "typeof(coords)"); // TODO: always "object"
	assertEqual(7, coords.getX(0), "coords.getX(0)");
	assertEqual(8, coords.getY(0), "coords.getY(0)");
	assertEqual(9, coords.getZ(0), "coords.getZ(0)");
	assertEqual(3, coords.getX(1), "coords.getX(1)");
	assertEqual(3, coords.getY(1), "coords.getY(1)");
	assertEqual(3, coords.getZ(1), "coords.getZ(1)");
	
	assertEqual(0, geom.area(), "geom.area()");
	assertEqual(6.4031242374328485, geom.length(), "geom.length()");
	
	report();
};

TestGeometry.prototype.testCreateLineStringIllegal = function() {
	WScript.Echo("testCreateLineStringIllegal");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 0);
	var geom = geos.createLineString(cs);
	
	report();
};

TestGeometry.prototype.testCreateLinearRing = function() {
	WScript.Echo("testCreateLinearRing");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(4, 3);
	cs.setX(0, 7);
	cs.setY(0, 8);
	cs.setZ(0, 9);
	cs.setX(1, 3);
	cs.setY(1, 3);
	cs.setZ(1, 3);
	cs.setX(2, 11);
	cs.setY(2, 15.2);
	cs.setZ(2, 2);
	cs.setX(3, 7);
	cs.setY(3, 8);
	cs.setZ(3, 9);
	
	var geom = geos.createLinearRing(cs);
//	assertEqual("ILinearRing", typeof(geom), "typeof(geom)"); // TODO: always "object"
	assertEqual("LinearRing", geom.geomType(), "geom.geomType()");
	assertEqual(geos.GEOS_LINEARRING, geom.typeId(), "geom.typeId()");
	
	assertEqual(false, geom.isEmpty(), "geom.isEmpty()");
	assertEqual(true, geom.isValid(), "geom.isValid()");
	assertEqual(true, geom.isSimple(), "geom.isSimple()");
	assertEqual(true, geom.isRing(), "geom.isRing()");
	assertEqual(true, geom.hasZ(), "geom.hasZ()");
	
	assertEqual(1, geom.getNumGeometries(), "geom.getNumGeometries()");
	
	var coords = geom.getCoordSeq();
//	assertEqual("ICoordinateSequence", typeof(coords), "typeof(coords)"); // TODO: always "object"
	assertEqual(7, coords.getX(0), "coords.getX(0)");
	assertEqual(8, coords.getY(0), "coords.getY(0)");
	assertEqual(9, coords.getZ(0), "coords.getZ(0)");
	assertEqual(3, coords.getX(1), "coords.getX(1)");
	assertEqual(3, coords.getY(1), "coords.getY(1)");
	assertEqual(3, coords.getZ(1), "coords.getZ(1)");
	assertEqual(11, coords.getX(2), "coords.getX(2)");
	assertEqual(15.2, coords.getY(2), "coords.getY(2)");
	assertEqual(2, coords.getZ(2), "coords.getZ(2)");
	assertEqual(7, coords.getX(3), "coords.getX(3)");
	assertEqual(8, coords.getY(3), "coords.getY(3)");
	assertEqual(9, coords.getZ(3), "coords.getZ(3)");
	
	assertEqual(0, geom.area(), "geom.area()");
	assertEqual(29.228665330091953, geom.length(), "geom.length()");
	
	report();
};

TestGeometry.prototype.testCreateLinearRingIllegal = function() {
	WScript.Echo("testCreateLinearRingIllegal");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 0);
	var geom = geos.createLinearRing(cs);
	
	report();
};

TestGeometry.prototype.testCreatePolygon = function() {
	WScript.Echo("testCreatePolygon");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(5, 2);
	cs.setX(0, 0);
	cs.setY(0, 0);
	
	cs.setX(1, 0);
	cs.setY(1, 10);
	
	cs.setX(2, 10);
	cs.setY(2, 10);
	
	cs.setX(3, 10);
	cs.setY(3, 0);
	
	cs.setX(4, 0);
	cs.setY(4, 0);
	var shell = geos.createLinearRing(cs);
	
	var geom = geos.createPolygon(shell, null);
//	assertEqual("IPolygon", typeof(geom), "typeof(geom)"); // TODO: always "object"
	assertEqual("Polygon", geom.geomType(), "geom.geomType()");
	assertEqual(geos.GEOS_POLYGON, geom.typeId(), "geom.typeId()");
	
	assertEqual(false, geom.isEmpty(), "geom.isEmpty()");
	assertEqual(true, geom.isValid(), "geom.isValid()");
	assertEqual(true, geom.isSimple(), "geom.isSimple()");
	assertEqual(false, geom.isRing(), "geom.isRing()");
	assertEqual(true, geom.hasZ(), "geom.hasZ()");
	
	assertEqual(1, geom.getNumGeometries(), "geom.getNumGeometries()");
	
	var exteriorRing = geom.getExteriorRing();
	assertEqual(true, shell.equals(exteriorRing), "shell.equals(exteriorRing)");
	assertEqual(0, geom.getNumInteriorRings(), "geom.getNumInteriorRings()");
	
	//assert geom.getInteriorRingN(1);
	
	assertEqual(100, geom.area(), "geom.area()");
	assertEqual(40, geom.length(), "geom.length()");
	
	report();
};

TestGeometry.prototype.testCreatePolygonWithHoles = function() {
	WScript.Echo("testCreatePolygonWithHoles");
	
	// Polygon shell
	var cs = geos.CoordinateSequence.new_CoordinateSequence(5, 2);
	cs.setX(0, 0);
	cs.setY(0, 0);
	
	cs.setX(1, 0);
	cs.setY(1, 10);
	
	cs.setX(2, 10);
	cs.setY(2, 10);
	
	cs.setX(3, 10);
	cs.setY(3, 0);
	
	cs.setX(4, 0);
	cs.setY(4, 0);
	var shell = geos.createLinearRing(cs);
	
	// Hole 1
	var cs1 = geos.CoordinateSequence.new_CoordinateSequence(5, 2);
	cs1.setX(0, 2);
	cs1.setY(0, 2);
	
	cs1.setX(1, 2);
	cs1.setY(1, 4);
	
	cs1.setX(2, 4);
	cs1.setY(2, 4);
	
	cs1.setX(3, 4);
	cs1.setY(3, 2);
	
	cs1.setX(4, 2);
	cs1.setY(4, 2);
	var hole1 = geos.createLinearRing(cs1);
	
	// Hole 2
	var cs2 = geos.CoordinateSequence.new_CoordinateSequence(5, 2);
	cs2.setX(0, 6);
	cs2.setY(0, 6);
	
	cs2.setX(1, 6);
	cs2.setY(1, 8);
	
	cs2.setX(2, 8);
	cs2.setY(2, 8);
	
	cs2.setX(3, 8);
	cs2.setY(3, 6);
	
	cs2.setX(4, 6);
	cs2.setY(4, 6);
	var hole2 = geos.createLinearRing(cs2);
	
	var holes = WScript.CreateObject("Scripting.Dictionary"); // for variant array
	holes.add(0, hole1);
	holes.add(1, hole2);
	var geom = geos.createPolygon(shell, holes.items());
//	assertEqual("IPolygon", typeof(geom), "typeof(geom)"); // TODO: always "object"
	assertEqual("Polygon", geom.geomType(), "geom.geomType()");
	assertEqual(geos.GEOS_POLYGON, geom.typeId(), "geom.typeId()");
	
	assertEqual(false, geom.isEmpty(), "geom.isEmpty()");
	assertEqual(true, geom.isValid(), "geom.isValid()");
	assertEqual(true, geom.isSimple(), "geom.isSimple()");
	assertEqual(false, geom.isRing(), "geom.isRing()");
	assertEqual(true, geom.hasZ(), "geom.hasZ()");
	
	assertEqual(1, geom.getNumGeometries(), "geom.getNumGeometries()");
	
	var exteriorRing = geom.getExteriorRing()
	assertEqual(true, shell.equals(exteriorRing), "shell.equals(exteriorRing)");
	
	assertEqual(2, geom.getNumInteriorRings(), "geom.getNumInteriorRings()");
	assertEqual(true, hole1.equals(geom.getInteriorRingN(0)), "hole1.equals(geom.getInteriorRingN(0))");
	assertEqual(true, hole2.equals(geom.getInteriorRingN(1)), "hole2.equals(geom.getInteriorRingN(1))");
	
	assertEqual(92, geom.area(), "geom.area()");
	assertEqual(56, geom.length(), "geom.length()");
	
	report();
};

TestGeometry.prototype.testDistance = function() {
	WScript.Echo("testDistance");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2);
	cs.setX(0, 0);
	cs.setY(0, 0);
	var geom1 = geos.createPoint(cs);
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2);
	cs.setX(0, 3);
	cs.setY(0, 4);
	var geom2 = geos.createPoint(cs);
	
	assertEqual(5, geom1.distance(geom2), "geom1.distance(geom2)");
	
	report();
};


var test = new TestGeometry();
test.testCreatePoint();
//test.testCreatePointIllegal();
test.testCreateLineString();
//test.testCreateLineStringIllegal();
test.testCreateLinearRing();
//test.testCreateLinearRingIllegal();
test.testCreatePolygon();
test.testCreatePolygonWithHoles();
test.testDistance();
