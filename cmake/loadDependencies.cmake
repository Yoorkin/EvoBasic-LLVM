set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dependencies)

function(ForceDownload packName downloadPath expectedHash)
    message(STATUS "Downloading ${packName}")
    file(
            DOWNLOAD ${downloadPath}
            ${DEPENDENCIES_DIR}/${packName}
            SHOW_PROGRESS
            EXPECTED_HASH SHA1=${expectedHash}
    )
endfunction()

function(Load_Dependencies packName downloadPath expectedHash)
    if(NOT EXISTS ${DEPENDENCIES_DIR}/${packName})
        ForceDownload(${packName} ${downloadPath} ${expectedHash})
    endif()
    file(SHA1 ${DEPENDENCIES_DIR}/${packName} LOCALFILE_HASH)
    if(NOT ${LOCALFILE_HASH} EQUAL ${expectedHash})
        ForceDownload("${packName}" ${downloadPath} ${expectedHash})
    endif()
    message(STATUS "Extracting ${packName} from ${DEPENDENCIES_DIR}")
    file(ARCHIVE_EXTRACT INPUT ${DEPENDENCIES_DIR}/${packName} DESTINATION ${DEPENDENCIES_DIR})
    message(STATUS "${packName} extract done.")
endfunction()