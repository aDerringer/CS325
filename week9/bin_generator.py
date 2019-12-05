import sys
import random

def main():
   cases = int(sys.argv[1])

   file = open(sys.argv[2], "w")

   file.write("{}\n".format(cases))

   for i in range(cases):
      capacity = random.randrange(10, 1000)
      items = random.randrange(10, 1000)
      file.write("{}\n".format(capacity))
      file.write("{}\n".format(items))

      for j in range(items - 1):
         file.write("{} ".format(random.randrange(1, capacity)))

      if i == cases - 1:
         file.write("{}".format(random.randrange(1, capacity)))
      else:
         file.write("{}\n".format(random.randrange(1, capacity)))

   file.close()


main()




   
