Option Explicit

Sub report(expected, result, arg, desc, op, arg1, arg2, arg3)
	Dim message
	message = "file:" & vbTab & arg & vbCrLf _
			& "desc:" & vbTab & desc & vbCrLf _
			& "op:" & vbTab & op & vbCrLf _
			& "arg1:" & vbTab & CStr(arg1) & vbCrLf _
			& "arg2:" & vbTab & CStr(arg2) & vbCrLf _
			& "arg3:" & vbTab & CStr(arg3) & vbCrLf _
			& "-------------------------------------------------------" & vbCrLf
	If expected <> result Then
		message = message & "=>Failed!" & vbCrLf
	Else
		message = message & "=>Succeeded!" & vbCrLf
	End If
	message = message & "expected:" & vbTab & CStr(expected) & vbCrLf & "result:" & vbTab & CStr(result)
	WScript.Echo message
End Sub

If WScript.Arguments.Count = 0 Then
	WScript.Echo "Usage: TODO:"
	WScript.Quit 1
End If

Dim arg
For Each arg In WScript.Arguments
	If LCase(Right(arg, 4)) <> ".xml" Then
		WScript.Echo "Invalid extension. Please specify *.xml"
		WScript.Quit 2
	End If
	
	Dim xmldom
	Set xmldom = WScript.CreateObject("Microsoft.XMLDOM")
	xmldom.Load arg
	
	Dim nodeCases
	Set nodeCases = xmldom.getElementsByTagName("case")
	
	Dim nodeCase
	For Each nodeCase In nodeCases
		Dim node1, nodeTest
		For Each node1 In nodeCase.childNodes
			Dim desc, a, b
			Select Case node1.nodeName
				Case "desc"
					desc = node1.text
				Case "a"
					a = node1.text
				Case "b"
					b = node1.text
				Case "test"
					Set nodeTest = node1
					Dim node2, nodeOp
					For Each node2 In nodeTest.childNodes
						If node2.nodeName = "op" Then
							Set nodeOp = node2
							Dim op, arg1, arg2, arg3, expected
							op = nodeOp.getAttribute("name")
							arg1 = nodeOp.getAttribute("arg1")
							arg2 = nodeOp.getAttribute("arg2")
							arg3 = nodeOp.getAttribute("arg3")
							expected = nodeOp.text
							If expected = "false" Then
								expected = False
							ElseIf expected = "true" Then
								expected = True
							End If
							
							Dim geos, reader, writer
							Set geos = WScript.CreateObject("geos.geos")
							Set reader = geos.WktReader.new_WktReader()
							Set writer = geos.WktWriter.new_WktWriter()
							
							Dim geomA, geomB
							If UCase(arg1) = "A" Then
								Set geomA = reader.read(a)
							End If
							If UCase(arg2) = "B" Then
								Set geomB = reader.read(b)
							End If
							
							Dim result
							Select Case LCase(op)
								Case "intersection"
									Set result = geomA.intersection(geomB)
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, ""
								Case "buffer"
									arg3 = CDbl(arg3)
									If IsNull(arg2) Then
										arg2 = 8
									Else
										arg2 = CLng(arg2)
									End If
									Set result = geomA.buffer(arg3, arg2)
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, arg3
								Case "convexhull"
									Set result = geomA.convexhull()
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, "", ""
								Case "difference"
									Set result = geomA.difference(geomB)
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, ""
								Case "symdifference"
									Set result = geomA.symDifference(geomB)
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, ""
								Case "getboundary"
									Set result = geomA.boundary()
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, "", ""
								Case "union"
									Set result = geomA.Union(geomB)
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, arg2, ""
								Case "pointonsurface"
									Set result = geomA.pointOnSurface()
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, "", ""
								Case "getcentroid"
									Set result = geomA.getCentroid()
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, "", ""
								Case "relate"
									result = geomA.relate(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "linemerge"
									Set result = geomA.lineMerge()
									Set expected = reader.read(expected)
									report writer.write(expected), writer.write(result), arg, desc, op, arg1, "", ""
								Case "relatePattern"
									result = geomA.relatePattern(geomB, arg3)
									report expected, result, arg, desc, op, arg1, arg2, arg3
								Case "disjoint"
									result = geomA.disjoint(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "touches"
									result = geomA.touches(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "intersects"
									result = geomA.intersects(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "crosses"
									result = geomA.crosses(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "within"
									result = geomA.within(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "contains"
									result = geomA.contains(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "overlaps"
									result = geomA.overlaps(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "equals"
									result = geomA.equals(geomB)
									report expected, result, arg, desc, op, arg1, arg2, ""
								Case "isempty"
									result = geomA.isEmpty()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "isvalid"
									result = geomA.isValid()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "issimple"
									result = geomA.isSimple()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "isring"
									result = geomA.isRing()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "hasz"
									result = geomA.hasZ()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "area"
									result = geomA.area()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "length"
									result = geomA.length()
									report expected, result, arg, desc, op, arg1, "", ""
								Case "distance"
									result = geomA.distance()
									report expected, result, arg, desc, op, arg1, "", ""
							End Select
						End If
					Next
			End Select
		Next
	Next
Next
