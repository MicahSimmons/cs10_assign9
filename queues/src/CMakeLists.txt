

add_definitions(-Wno-zero-length-array)

#############################
# Platform specific include directories
#############################


#############################
# Check Source Dependencies
#############################
set(SRC_FILES  main.cpp
               app.cpp
               door.cpp
               customer.cpp
               waiting.cpp
               service.cpp
               survey.cpp
   )


#############################
# Check Library Dependencies
#############################
set(LINK_LIBS
   )

#############################
# Compile to Executable Target
#############################
add_executable(${PROGRAM_EXE_NAME} ${SRC_FILES})
target_link_libraries(${PROGRAM_EXE_NAME} ${LINK_LIBS} )
