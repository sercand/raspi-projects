FIND_PATH(WIRINGPI_INCLUDE_DIRS NAMES wiringPi.h
  PATHS
  /usr
  /usr/local
  /opt
  PATH_SUFFIXES
)

FIND_LIBRARY(WIRINGPI_LIBRARIES NAMES wiringPi
  PATHS
  /usr
  /usr/local
  /opt
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(wiringPi DEFAULT_MSG WIRINGPI_LIBRARIES WIRINGPI_INCLUDE_DIRS)

MARK_AS_ADVANCED(WIRINGPI_INCLUDE_DIRS WIRINGPI_LIBRARIES)