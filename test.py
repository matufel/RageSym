import angr
import pyvex
import archinfo

proj = angr.Project("./testPrograms/simpleIfs")
obj = proj.loader.main_object

# print("for entry:")
# irsb = proj.factory.block(proj.entry).vex
# irsb.pp()
# print(irsb.next)

print("for main:")
irsb = proj.factory.block(0x0000000000401149).vex
irsb.pp()
for stmt in irsb.statements:
    stmt.pp()

# print(irsb.next)
# addr = int(str(irsb.next), 16)
# print(obj.reverse_plt[addr])
