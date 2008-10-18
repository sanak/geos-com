# Microsoft Developer Studio Project File - Name="geos_lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=geos_lib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "geos_lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "geos_lib.mak" CFG="geos_lib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "geos_lib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "geos_lib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\source\headers" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\Release\geos.lib"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\..\..\source\headers" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\Debug\geosd.lib"

!ENDIF 

# Begin Target

# Name "geos_lib - Win32 Release"
# Name "geos_lib - Win32 Debug"
# Begin Group "algorithm"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\algorithm\CentroidArea.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\CentroidLine.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\CentroidPoint.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\CGAlgorithms.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\ConvexHull.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\HCoordinate.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\InteriorPointArea.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\InteriorPointLine.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\InteriorPointPoint.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\LineIntersector.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\MCPointInRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\MinimumDiameter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\NotRepresentableException.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\PointLocator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\RobustDeterminant.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\SimplePointInAreaLocator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\SimplePointInRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\algorithm\SIRtreePointInRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\algorithm"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\algorithm"

!ENDIF 

# End Source File
# End Group
# Begin Group "geom"

# PROP Default_Filter ""
# Begin Group "util2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\geom\util\CoordinateOperation.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\util\GeometryEditor.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\util\GeometryTransformer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\util\ShortCircuitedGeometryVisitor.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source\geom\Coordinate.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\CoordinateArraySequence.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\CoordinateArraySequenceFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\CoordinateSequence.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Dimension.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Envelope.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Geometry.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\GeometryCollection.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\GeometryComponentFilter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\GeometryFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\GeometryList.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\IntersectionMatrix.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\LinearRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\LineSegment.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\LineString.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Location.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\MultiLineString.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\MultiPoint.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\MultiPolygon.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Point.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Polygon.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\PrecisionModel.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geom\Triangle.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geom"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geom"

!ENDIF 

# End Source File
# End Group
# Begin Group "geomgraph"

# PROP Default_Filter ""
# Begin Group "index2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\MonotoneChainEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\MonotoneChainIndexer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SegmentIntersector.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SimpleEdgeSetIntersector.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SimpleMCSweepLineIntersector.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SimpleSweepLineIntersector.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SweepLineEvent.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\index\SweepLineSegment.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph\index"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Depth.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\DirectedEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\DirectedEdgeStar.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Edge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeEnd.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeEndStar.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeIntersection.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeIntersectionList.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeList.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeNodingValidator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\EdgeRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\GeometryGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\GraphComponent.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Label.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Node.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\NodeFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\NodeMap.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\PlanarGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Position.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\Quadrant.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\geomgraph\TopologyLocation.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\geomgraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\geomgraph"

!ENDIF 

# End Source File
# End Group
# Begin Group "index"

# PROP Default_Filter ""
# Begin Group "bintree"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\index\bintree\Bintree.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\bintree\Interval.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\bintree\Key.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\bintree\Node.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\bintree\NodeBase.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\bintree\Root.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\bintree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\bintree"

!ENDIF 

# End Source File
# End Group
# Begin Group "chain"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\index\chain\MonotoneChain.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\chain"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\chain"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\chain\MonotoneChainBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\chain"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\chain"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\chain\MonotoneChainOverlapAction.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\chain"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\chain"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\chain\MonotoneChainSelectAction.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\chain"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\chain"

!ENDIF 

# End Source File
# End Group
# Begin Group "quadtree"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\DoubleBits.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\IntervalSize.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\Key.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\Node.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\NodeBase.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\Quadtree.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\quadtree\Root.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\quadtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\quadtree"

!ENDIF 

# End Source File
# End Group
# Begin Group "strtree"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\index\strtree\AbstractNode.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\strtree\AbstractSTRtree.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\strtree\Interval.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\strtree\ItemBoundable.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\strtree\SIRtree.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\strtree\STRtree.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\strtree"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\strtree"

!ENDIF 

# End Source File
# End Group
# Begin Group "sweepline"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\index\sweepline\SweepLineEvent.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\sweepline"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\sweepline"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\sweepline\SweepLineIndex.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\sweepline"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\sweepline"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\index\sweepline\SweepLineInterval.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\index\sweepline"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\index\sweepline"

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "io"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\io\ByteOrderDataInStream.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\ByteOrderValues.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\ParseException.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\StringTokenizer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\Unload.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\WKBReader.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\WKBWriter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\WKTReader.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\WKTWriter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\io\Writer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\io"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\io"

!ENDIF 

# End Source File
# End Group
# Begin Group "noding"

# PROP Default_Filter ""
# Begin Group "snapround"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\noding\snapround\HotPixel.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\snapround\MCIndexPointSnapper.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\snapround\MCIndexSnapRounder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\snapround\SimpleSnapRounder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source\noding\FastNodingValidator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\IntersectionAdder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\IntersectionFinderAdder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\IteratedNoder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\MCIndexNoder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\NodingValidator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\Octant.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\ScaledNoder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\SegmentNode.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\SegmentNodeList.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\SegmentString.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\SimpleNoder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\noding\SingleInteriorIntersectionFinder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\noding"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\noding"

!ENDIF 

# End Source File
# End Group
# Begin Group "operation"

# PROP Default_Filter ""
# Begin Group "buffer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\BufferBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\BufferOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\BufferSubgraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\OffsetCurveBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\OffsetCurveSetBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\OffsetCurveVertexList.h

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\RightmostEdgeFinder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\buffer\SubgraphDepthLocater.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "distance"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\distance\ConnectedElementLocationFilter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\distance\ConnectedElementPointFilter.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\distance\DistanceOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\distance\GeometryLocation.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "linemerge"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\EdgeString.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\LineMergeDirectedEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\LineMergeEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\LineMergeGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\LineMerger.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\linemerge\LineSequencer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "overlay"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\EdgeSetNoder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\ElevationMatrix.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\ElevationMatrixCell.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\FuzzyPointLocator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\LineBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\MaximalEdgeRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\MinimalEdgeRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\OffsetPointGenerator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\OverlayNodeFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\OverlayOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\OverlayResultValidator.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\PointBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\overlay\PolygonBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "polygonize"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\polygonize\EdgeRing.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\polygonize\PolygonizeDirectedEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\polygonize\PolygonizeEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\polygonize\PolygonizeGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\polygonize\Polygonizer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "predicate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\predicate\RectangleContains.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\predicate\RectangleIntersects.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\predicate\SegmentIntersectionTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "relate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\relate\EdgeEndBuilder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\EdgeEndBundle.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\EdgeEndBundleStar.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\RelateComputer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\RelateNode.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\RelateNodeFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\RelateNodeGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\relate\RelateOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "valid"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\operation\valid\ConnectedInteriorTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\ConsistentAreaTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\IsValidOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\QuadtreeNestedRingTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\RepeatedPointTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\SimpleNestedRingTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\SweeplineNestedRingTester.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\valid\TopologyValidationError.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source\operation\GeometryGraphOperation.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\operation\IsSimpleOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\operation\valid"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\operation\valid"

!ENDIF 

# End Source File
# End Group
# Begin Group "planargraph"

# PROP Default_Filter ""
# Begin Group "algorithm2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\planargraph\algorithm\ConnectedSubgraphFinder.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source\planargraph\DirectedEdge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\DirectedEdgeStar.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\Edge.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\Node.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\NodeMap.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\PlanarGraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\planargraph\Subgraph.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\planargraph"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\planargraph"

!ENDIF 

# End Source File
# End Group
# Begin Group "precision"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\precision\CommonBits.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\CommonBitsOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\CommonBitsRemover.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\EnhancedPrecisionOp.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\GeometrySnapper.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\LineStringSnapper.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\precision\SimpleGeometryPrecisionReducer.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\precision"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\precision"

!ENDIF 

# End Source File
# End Group
# Begin Group "simplify"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\simplify\DouglasPeuckerLineSimplifier.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\DouglasPeuckerSimplifier.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\LineSegmentIndex.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\TaggedLineSegment.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\TaggedLinesSimplifier.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\TaggedLineString.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\TaggedLineStringSimplifier.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\simplify\TopologyPreservingSimplifier.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\simplify"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\simplify"

!ENDIF 

# End Source File
# End Group
# Begin Group "util"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source\util\Assert.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\util"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\util"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\util\GeometricShapeFactory.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\util"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\util"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\util\math.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\util"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\util"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\source\util\Profiler.cpp

!IF  "$(CFG)" == "geos_lib - Win32 Release"

# PROP Intermediate_Dir "Release\util"

!ELSEIF  "$(CFG)" == "geos_lib - Win32 Debug"

# PROP Intermediate_Dir "Debug\util"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
