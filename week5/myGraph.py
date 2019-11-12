#################################################
# Program: Wrestling Rivals
# Author: Andrew Derringer
# Last Modified: 11/11/2019
# Summary: Class structures for a graph of vertices
#		and the vertices themselves.
#################################################
class Vertex:
   def __init__(self, n, c):
      self.name = n
      self.neighbors = []
      self.color = c

   def add_neighbor(self, v):
      if v not in self.neighbors:
         self.neighbors.append(v)

   def setColor(self, c):
      self.color = c

   def finalColor(self):
      if len(self.neighbors) > 0:
         k = self.neighbors[0]
         if k.color == "red":
            self.color = "blue"
         elif k.color == "blue":
            self.color = "red"
         elif k.color == "white":
            self.color = "blue"
            k.color = "red"

   def possible(self):
      for n in self.neighbors:
         if n.color == self.color:
            return False
      return True


class Graph:
   vertices = {}

   def add_vertex(self, vertex):
      if isinstance(vertex, Vertex) and vertex.name not in self.vertices:
         self.vertices[vertex.name] = vertex
         return True
      else:
         return False

   def getVertex(self, p1):
         for v in self.vertices:
            if self.vertices[v].name == p1:
               return self.vertices[v]

   def printTeams(self):
      good = "Babyfaces: "
      bad = "Heels: "

      for v in self.vertices:
         if self.vertices[v].color == "white":
            self.vertices[v].finalColor()

         if self.vertices[v].possible() == False:
            print("No impossible...")
            return

         if self.vertices[v].color == "blue":
            good += "{} ".format(self.vertices[v].name)
         else:
            bad += "{} ".format(self.vertices[v].name)

      print("Yes Possible...")
      print(good)
      print(bad)

   def assignColors(self, a, b):
      if a.color != "white" and a.color == b.color:
         return False
      elif a.color == "blue" and b.color == "white":
         b.setColor("red")
      elif a.color == "red" and b.color == "white":
         b.color = "blue"
      elif b.color == "blue" and a.color == "white":
         a.color = "red"
      elif b.color == "red" and a.color == "white":
         a.color = "blue"
      return True


