===== README =====
	This repository is for the control version of the code developed in the CGRA Classes at FEUP.
	We use OPENGL, GLUI, GLUT, GLU libraries and one developed by teachers: CGF lib
	
===== Authors =====
	André Freitas - p.andrefreitas@gmail.com
	Vasco Gonçalves - vascofg@gmai.com

===== BASIC SETUP (Eclipse@Ubuntu) =====
	(1) Install libraries
	sudo apt-get install freeglut3 freeglut3-dev
	sudo apt-get install binutils-gold
	sudo apt-get install libglui-dev

	(2) Create a project in eclipse
	File/New/C++ Project

	(3) Upload the all the files from baseproject folder
	The folder that is inside in this repository
	
	(4) Add linker libraries in project properties
	Project / Properties / C/C++Build / Settings -> GCC C++ Linker / Libraries
	add: glut, GLU, glui and GL. This will produce gcc -lglut -lGLU -lglui -lGL (...)

	(5) Compile project and confirm it runs

===== CHANGELOG =====
	(1)  2012-03-06 Vasco Gonçalves
		*tp1/part2 : solved exercice 5
	(2) 2012-03-11 André Freitas
		*README.TXT : added project description and basic setup guide
	

