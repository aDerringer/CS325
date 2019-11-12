#################################################
# Program: Wrestling Rivals
# Author: Andrew Derringer
# Last Modified: 11/11/2019
# Summary: Opens file, reads its contents and uses
#	imported classes to find relationships
#################################################

import sys
from myGraph import Graph, Vertex

def readFile(filename, roster):
   iFile = open(filename, "r")
 
   # read lines of names from file and put into graph unconnected
   rosterCount = int(iFile.readline())
   for line in range(rosterCount):
      if line == 0:
         roster.add_vertex(Vertex((iFile.readline()).replace('\n', ''), "blue"))
      else:
         roster.add_vertex(Vertex((iFile.readline()).replace('\n', ''), "white"))

   # go through pairs and connect names to already made vertices
   # connect the vertices and assign colors
   pairs = int(iFile.readline())
   for line in range(pairs):
      p1, p2 = (iFile.readline()).split(" ")        
      p2.rstrip('\r\n')
      a = roster.getVertex(p1)
      b = roster.getVertex(p2[0:-1])
      a.add_neighbor(b)
      b.add_neighbor(a)
      roster.assignColors(a, b)

   iFile.close()

def rivalries():
   roster = Graph()
   readFile(sys.argv[1], roster)
   roster.printTeams()

rivalries()
