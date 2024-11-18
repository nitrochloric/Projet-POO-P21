# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Projet_Groupe3_IHM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Projet_Groupe3_IHM_autogen.dir\\ParseCache.txt"
  "Projet_Groupe3_IHM_autogen"
  )
endif()
