function report(expected, result, arg, desc, op, arg1, arg2, arg3) {
	var message = "file:" + "\t" + arg + "\n"
			+ "desc:" + "\t" + desc + "\n"
			+ "op:" + "\t" + op + "\n"
			+ "arg1:" + "\t" + arg1 + "\n"
			+ "arg2:" + "\t" + arg2 + "\n"
			+ "arg3:" + "\t" + arg3 + "\n"
			+ "-------------------------------------------------------" + "\n";
	if (expected == result) {
		message += "=>Succeeded!" + "\n";
	} else {
		message += "=>Failed!" + "\n";
	}
	
	message += "expected:" + "\t" + expected + "\n" + "result:" + "\t" + result;
	WScript.Echo(message);
};

if (WScript.Arguments.length == 0) {
	WScript.Echo("Please drop test xml file on this script, or execute command line as follows" + "\n"
				+ ">cscript test_xml.vbs [test xml file]");
	WScript.Quit(1);
}

for (var i = 0; i < WScript.Arguments.length; i++) {
	var arg = WScript.Arguments.Item(i);
	if (arg.substr(arg.length - 4, 4).toLowerCase() != ".xml") {
		WScript.Echo("Invalid extension. Please specify *.xml");
		WScript.Quit(2);
	}
	
	var xmldom = WScript.CreateObject("Microsoft.XMLDOM");
	xmldom.load(arg);
	
	var nodecases = xmldom.getElementsByTagName("case");
	for (var j = 0; j < nodecases.length; j++) {
		var nodecase = nodecases[j];
		var nodeTest;
		for (var k = 0; k < nodecase.childNodes.length; k++) {
			var node1 = nodecase.childNodes[k];
			var desc, a, b;
			switch (node1.nodeName) {
				case "desc":
					desc = node1.text;
					break;
				case "a":
					a = node1.text;
					break;
				case "b":
					b = node1.text;
					break;
				case "test":
					nodeTest = node1;
					var nodeOp;
					for (var l = 0; l < nodeTest.childNodes.length; l++) {
						var node2 = nodeTest.childNodes[l];
						if (node2.nodeName == "op") {
							nodeOp = node2;
							var op, arg1, arg2, arg3, expected;
							op = nodeOp.getAttribute("name");
							arg1 = nodeOp.getAttribute("arg1");
							arg2 = nodeOp.getAttribute("arg2");
							arg3 = nodeOp.getAttribute("arg3");
							expected = nodeOp.text;
							if (expected == "false") {
								expected = false;
							} else if (expected == "true") {
								expected = true;
							}
							
							var geos = WScript.CreateObject("geos.geos");
							var reader = geos.WktReader.new_WktReader();
							var writer = geos.WktWriter.new_WktWriter();
							
							var geomA, geomB;
							if ((typeof(arg1) == "string") && (arg1.toUpperCase() == "A")) {
								geomA = reader.read(a);
							}
							if ((typeof(arg2) == "string") && (arg2.toUpperCase() == "B")) {
								geomB = reader.read(b);
							}
							
							var result;
							switch (op.toLowerCase()) {
								case "intersection":
									result = geomA.intersection(geomB);
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, "");
									break;
								case "buffer":
									arg3 = parseFloat(arg3);
									if (typeof(arg2) == "undefined") {
										arg2 = 8;
									} else {
										arg2 = parseInt(arg2);
									}
									result = geomA.buffer(arg2, arg3);
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, arg3);
									break;
								case "convexhull":
									result = geomA.convexhull();
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, "", "");
									break;
								case "difference":
									result = geomA.difference(geomB);
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, "");
									break;
								case "symdifference":
									result = geomA.symDifference(geomB);
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, "");
									break;
								case "getboundary":
									result = geomA.boundary();
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, "", "");
									break;
								case "union":
									result = geomA.Union(geomB);
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, "");
									break;
								case "pointonsurface":
									result = geomA.pointOnSurface();
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, "", "");
									break;
								case "getcentroid":
									result = geomA.getCentroid();
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, "", "");
									break;
								case "relate":
									result = geomA.relate(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "linemerge":
									result = geomA.lineMerge();
									expected = reader.read(expected);
									report(writer.write(expected), writer.write(result), arg, desc, op, arg1, "", "");
									break;
								case "relatePattern":
									result = geomA.relatePattern(geomB, arg3);
									report(expected, result, arg, desc, op, arg1, arg2, arg3);
									break;
								case "disjoint":
									result = geomA.disjoint(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "touches":
									result = geomA.touches(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "intersects":
									result = geomA.intersects(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "crosses":
									result = geomA.crosses(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "within":
									result = geomA.within(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "contains":
									result = geomA.contains(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "overlaps":
									result = geomA.overlaps(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "equals":
									result = geomA.equals(geomB);
									report(expected, result, arg, desc, op, arg1, arg2, "");
									break;
								case "isempty":
									result = geomA.isEmpty();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "isvalid":
									result = geomA.isValid();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "issimple":
									result = geomA.isSimple();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "isring":
									result = geomA.isRing();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "hasz":
									result = geomA.hasZ();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "area":
									result = geomA.area();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "length":
									result = geomA.length();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
								case "distance":
									result = geomA.distance();
									report(expected, result, arg, desc, op, arg1, "", "");
									break;
							}
						}
					}
			}
		}
	}
}
