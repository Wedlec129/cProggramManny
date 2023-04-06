#используем си динам библиотеку в питоне

from ctypes import CDLL

fd=CDLL("./libpprint.so")

fd.pprint(b"i am python") #b типо байт код а не юникод


