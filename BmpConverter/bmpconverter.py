from PIL import Image
import sys
import os

print("Este programa convierte un .bmp de 24 bits a un arreglo const uint8_t.")
print("La información de color de cada pixel se almacena en dos bytes BIG ENDIAN")
print("El color se codifica en RGB565")

# Check at least 2 arguments (script name and input file)
if (len(sys.argv) <2):
     print("Ingrese Imagen.bmp en formato de 24 bits")
     sys.exit()
# Check the file extension
if (os.path.splitext(sys.argv[1])[1] != ".bmp"):
    print("La extensión no es .bmp")
    sys.exit()
# Open file
im = Image.open(os.path.split(sys.argv[1])[1])
# print(im.format,im.size,im.mode)
# Check BMP format, 24 bits and size
if (im.format != "BMP"):
    print("El archivo no es un .bmp")
    sys.exit()

if (im.mode != "RGB"):
    print("Ingrese un archivo bmp de 24 bits")
    sys.exit()
imHeight = im.height 
if (imHeight > 128):
    print("Ingrese un imagen menor a 128 bits de alto")
    sys.exit()

imWidth = im.width 
if (imWidth > 128):
    print("Ingrese un imagen menor a 128 bits de ancho")
    sys.exit()

im16 = im.convert

filename = os.path.splitext(sys.argv[1])[0]
with open(filename+".txt", 'w') as outFile:
    outFile.write("const uint8_t "+filename+"[] = { // ")
    outFile.write("size: " + str(im.width) +" w x " + str(im.height)+" h")
    outFile.write(os.linesep)
    pixelData = list(im.getdata())
    raw = imHeight-1
    col = 0
    pixelsPerLine = 8
    pixelsPerLineCounter = 0
    while raw > -1:
        while col < imWidth:
            red,green, blue = pixelData[raw*imWidth+col]
            color = ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | ((blue & 0xF8) >> 3)
            Hbyte,Lbyte = divmod(color,0x100)
            outFile.write("0x"+format(Hbyte,"02X"))
            outFile.write(", ")
            outFile.write("0x" + format(Lbyte,"02X"))
            if not ((raw == 0) and col == (imWidth-1)):
                outFile.write(", ")
            pixelsPerLineCounter += 1
            if(pixelsPerLineCounter == pixelsPerLine):
                pixelsPerLineCounter = 0
                outFile.write(os.linesep)
            col += 1 
        raw += -1
        col = 0
    outFile.write("};")
    outFile.write(os.linesep)
im.close()
print("Archivo exitosamente generado")