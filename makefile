output: LazyRoom.o LazyStudent.o main.o ResponsibleStudent.o Room.o StandardRoom.o Student.o WorkerRoom.o WorkerStudent.o ZoomSys.o
	g++ LazyRoom.o LazyStudent.o main.o ResponsibleStudent.o Room.o StandardRoom.o Student.o WorkerRoom.o WorkerStudent.o ZoomSys.o -o output
LazyRoom.o: LazyRoom.cpp LazyRoom.h Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h
	g++ -c LazyRoom.cpp
LazyStudent.o: LazyStudent.cpp LazyStudent.h Student.h Room.h ResponsibleStudent.h WorkerStudent.h Error.h
	g++ -c LazyStudent.cpp
main.o: main.cpp ZoomSys.h LazyRoom.h Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h WorkerRoom.h StandardRoom.h Error.h
	g++ -c main.cpp
ResponsibleStudent.o: ResponsibleStudent.cpp ResponsibleStudent.h Student.h
	g++ -c ResponsibleStudent.cpp
Room.o: Room.cpp Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h Error.h
	g++ -c Room.cpp
StandardRoom.o: StandardRoom.cpp StandardRoom.h Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h
	g++ -c StandardRoom.cpp
Student.o: Student.cpp Student.h Room.h ResponsibleStudent.h WorkerStudent.h LazyStudent.h
	g++ -c Student.cpp
WorkerRoom.o: WorkerRoom.cpp WorkerRoom.h Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h
	g++ -c WorkerRoom.cpp
WorkerStudent.o: WorkerStudent.cpp WorkerStudent.h Student.h Room.h ResponsibleStudent.h LazyStudent.h Error.h
	g++ -c WorkerStudent.cpp
ZoomSys.o: ZoomSys.cpp ZoomSys.h LazyRoom.h Room.h ResponsibleStudent.h Student.h WorkerStudent.h LazyStudent.h WorkerRoom.h StandardRoom.h Error.h
	g++ -c ZoomSys.cpp
clean:
	rm -f *.o

