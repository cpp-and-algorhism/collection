CMAKE_MINIMUM_REQUIRED (VERSION 3.13.0)
PROJECT (random)


SET (Boost_USE_MULTITHREADED      ON)

# パッケージを探索
# (だいたい次のような変数が設定される。XXXにパッケージ名)
#  XXX_FOUND
#  XXX_INCLUDE_DIRSまたはXXX_INCLUDES
#  XXX_LIBRARIESまたはXXX_LIBS
#  XXX_DEFINITIONS
FIND_PACKAGE (Boost 1.67.0 COMPONENTS random log log_setup thread iostreams program_options timer filesystem system)
#FIND_PACKAGE (Threads)
message("Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}") # /usr/local/include

# インクルードパスを指定する
INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}/include/
    ${Boost_INCLUDE_DIR}
)


# サブディレクトリ定義
ADD_SUBDIRECTORY (main)
