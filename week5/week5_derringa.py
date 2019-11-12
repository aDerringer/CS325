import sys

def buildArr(rows, cols):
   arr = [["" for i in range(cols)] for j in range(rows)]
   return arr

def readFile(filename, roster):
   iFile = open(filename, "r")
   #roster = {}

   rosterCount = int(iFile.readline())
   for line in range(rosterCount):
      roster.update({(iFile.readline()).replace('\n', ''): "white"})

   pairs = int(iFile.readline())
   #arr = buildArr(pairs, 2)
   print(roster)
   currPair = 0
   possible = True

   while currPair < pairs and possible == True:
      p1, p2 = (iFile.readline()).split(" ")
      #p2.rstrip('\r\n')
      print(p1)
      print(p2[0:-1])
      possible = rivalry(p1, p2[0:-1], roster)
      currPair += 1

   iFile.close()
   return possible


def rivalry(p1, p2, roster):
   possible = True
   if roster[p1] == roster[p2] and roster[p1] != "white":
      possible = False
   elif roster[p1] == "red":
      roster[p2] = "blue"
   elif roster[p2] == "red":
      roster[p1] = "blue"
   else:
      roster[p1] = "blue"
      roster[p2] = "red"

   return possible

def formPrint(roster):
   good = "Good guys: "
   bad = "Heels: "

   for wrestler in roster:
      if roster[wrestler] == "blue":
         good += "{}, ".format(wrestler)
      elif roster[wrestler] == "red":
         bad += "{}, ".format(wrestler)

   print(good[0:-2])
   print(bad[0:-2])

def rivalries():
   roster = {}
   possible = readFile(sys.argv[1], roster)

   print(roster)

   if possible == True:
      formPrint(roster)

rivalries()
