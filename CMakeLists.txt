cmake_minimum_required(VERSION 3.0)

project(RP2GE)

# Crée des variables avec les fichiers à compiler
set(HEADERS
	include/attaque.h
	include/Gameplay.h
 	include/James.h
 	include/Joueur.h
 	include/Laffont.h
	include/Personnage.h
	include/UI.h
	include/Client_sock.h
	)
	
set(SOURCE
 	src/Attaque.cpp
 	src/Gameplay.cpp
 	src/James.cpp
	src/Joueur.cpp
 	src/Laffont.cpp
 	src/Personnage.cpp
 	src/UI.cpp
	src/Client_sock.cpp
 	)

# add_library(RPg ${HEADERS} ${SOURCE})

 set(SRC
     src/main.cpp
     )


# exécutable
include_directories( include)
add_executable(RP2GE ${SRC} ${SOURCE} )

# target_link_libraries(RP2GE ${HEADERS} )
