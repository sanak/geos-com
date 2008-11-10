var geos = WScript.CreateObject("geos.geos")

var results = ""

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

function SridTest() {
};

SridTest.prototype.testSrid = function() {
	WScript.Echo("testSrid");
	
	var cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2);
	cs.setX(0, 7);
	cs.setY(0, 8);
	
	var geom1 = geos.createPoint(cs);
	geom1.setSRID(4326);
	
	assertEqual(4326, geom1.getSRID(), "geom1.getSRID()");
	
	report();
};

SridTest.prototype.testWriteSrid = function() {
	WScript.Echo("testWriteSrid");
	
	var reader = geos.WktReader.new_WktReader();
	var geom = reader.read("POINT(7 8)");
	geom.setSRID(4326);
	
	var writer = geos.WkbWriter.new_WkbWriter();
	// without srid
	writer.setIncludeSRID(false);
	var hex = writer.writeHex(geom);
	assertEqual("01010000000000000000001C400000000000002040", hex, "hex");
	
	// with srid
	writer.setIncludeSRID(true);
	hex = writer.writeHex(geom);
	assertEqual("0101000020E61000000000000000001C400000000000002040", hex, "hex");
	
	report();
};

SridTest.prototype.testRoundtripSrid = function() {
	WScript.Echo("testRoundtripSrid");
	
	var reader = geos.WktReader.new_WktReader();
	var geom1 = reader.read("POINT(7 8)");
	geom1.setSRID(4326);
	assertEqual(4326, geom1.getSRID(), "geom1.getSRID()");
	
	var writer = geos.WkbWriter.new_WkbWriter();
	writer.setIncludeSRID(true);
	hex = writer.writeHex(geom1);
	
	reader = geos.WkbReader.new_WkbReader();
	var geom2 = reader.readHex(hex);
	assertEqual(4326, geom2.getSRID(), "geom2.getSRID()");
	
	report();
};

SridTest.prototype.testReadSRID = function() {
	WScript.Echo("testReadSRID");
	
	// srid=4326;POINT(7 8)
	var xdr = "0101000020E61000000000000000001C400000000000002040"
	
	var reader = geos.WkbReader.new_WkbReader();
	var geom = reader.readHex(xdr);
	
	assertEqual(7, geom.getCoordSeq().getX(0), "geom.getCoordSeq().getX(0)");
	assertEqual(8, geom.getCoordSeq().getY(0), "geom.getCoordSeq().getY(0)");
	assertEqual(4326, geom.getSRID(), "geom.getSRID()");
	
	report();
};

var test = new SridTest();
test.testSrid();
test.testWriteSrid();
test.testRoundtripSrid();
test.testReadSRID();
