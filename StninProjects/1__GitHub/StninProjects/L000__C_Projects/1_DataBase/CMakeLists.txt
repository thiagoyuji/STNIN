cmake_minimum_required( VERSION 3.9 )
project( NpDB )

set (SOURCE_FILES src/Npdb_Test_C.c src/NpdbTypes.h src/Database/Dir/dirTreatment.c src/Database/Dir/dirTreatment.h src/Database/Npdb_Db_Types.h )

add_executable( NpDB ${SOURCE_FILES})
