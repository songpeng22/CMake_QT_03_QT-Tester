MACRO(RECURSIVE_SEARCH_DIR file_expression return_list)
    FILE(GLOB_RECURSE new_list ${file_expression})
    SET(dir_list "")
    # serching file and dir
    MESSAGE("serching file and dir:")
    FOREACH(file_path ${new_list})
        #MESSAGE("file: ${file_path}")
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        #MESSAGE("fileDir: ${dir_path}")
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    # required dir
    MESSAGE("this is required dir:")
    FOREACH(dir ${dir_list})
        MESSAGE("dir: ${dir}")
    ENDFOREACH()
    SET(${return_list} ${dir_list})
ENDMACRO()

MACRO(RECURSIVE_SEARCH_NAME file_expression return_list)
    FILE(GLOB_RECURSE new_list ${file_expression})
    SET(name_list "")
    # serching file and dir
    MESSAGE("serching file and dir:")
    FOREACH(file_path ${new_list})
        #MESSAGE("file: ${file_path}")
        GET_FILENAME_COMPONENT(filename ${file_path} NAME)
        #MESSAGE("filename: ${filename}")
        SET(name_list ${name_list} ${filename})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES name_list)
    # required name
    MESSAGE("this is required name:")
    FOREACH(name ${name_list})
        MESSAGE("dir: ${name}")
    ENDFOREACH()
    SET(${return_list} ${name_list})
ENDMACRO()
