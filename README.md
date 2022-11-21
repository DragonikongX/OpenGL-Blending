# OpenGL-Blending

Celem projektu było zaprezentowanie przykładowej sceny w przestrzeni 3D z punktu widzenia obserwatora, z dowolnego miejsca w przestrzeni.
Dodatkowo w projekcie zostały zaimplementowane operacje takie jak np. oświetlenie Blinna - Phonga wykonane przy pomocy shaderów, Mapa rozbłysków wykorzystująca dodatkowe tekstury wpływające na intensywność odbić światła, przeźroczystość tekstur wykonywana przy pomocy discardowania pixeli w shaderze oraz blending odpowiadający za symulacje mieszania barw obiektów na podstawie ich kanałów alfa.

## Instrukcja obsługi

Program, można uruchomić poprzez wybrane środowisko IDE (W moim przypadku było to
Visual Studio 2019) dzięki plikowi OpenGL2.sln. Natomiast nie zalecam korzystania z tego
sposobu ponieważ wymaga ono dodatkowego zlinkowania wszystkich plików bibliotek
przedstawionych w 3 punkcie. Zalecam natomiast uruchamiać program poprzez dołączony plik
OpenGL2.exe, znajdujący się w folderze EXE. W samej aplikacji sterumejmy przy pomocy
następujących przycisków:
W – Poruszanie do przodu
S – Poruszanie do tyłu
A – Poruszanie w lewo
D – Poruszanie w prawo
Mysz – Poruszanie myszą pozwala na obracanie kamerą według kierunku myszy

## Biblioteki i narzędzia:

- GLEW

- GLM

- stb_image

- OBJLoader

## Screeny:

![alt text](https://github.com/DragonikongX/OpenGL-Blending/blob/main/blen1.PNG?raw=true)

![alt text](https://github.com/DragonikongX/OpenGL-Blending/blob/main/blen2.PNG?raw=true)

![alt text](https://github.com/DragonikongX/OpenGL-Blending/blob/main/blen3.PNG?raw=true)
