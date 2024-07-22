import pyvex
import archinfo

#Converts a binary to VEX
def convert(binaryLocation):
    print("Converting binary at: {} to VEX IR".format(binaryLocation))
    #open file and read it as binary
    with open(binaryLocation, mode='rb') as file:
        data = file.read()
    #
    irsb = pyvex.lift(b"\x83\xf8\x01\x75\x32", 0x0, archinfo.get_host_arch())
    print(len(irsb.statements))
    i = 0
    for stmt in irsb.statements:
        # print(i)
        # i += 1
        stmt.pp()
    return

if __name__ == "__main__":
    convert("./testPrograms/simpleIfs")
    pass