/**
 * @mainpage pmdCam - documentation
 * @description ROS (Robot Operating System) based application to obtain and modify data from IFM camera and webcamera
 *
 * @section pmdCamServer pmdCamServer {input_xml_calibration_file}
 * @authors Łukasz Ilnicki, Maciej Przybylski
 * @details ROS node. Obtain data from IFMcam / IFMoffline and webcamera. Converts received data into Point Cloud.
 *
 * @section pmdGUI pmdGUI
 * @author Łukasz Ilnicki
 * @details ROS node. Provide graphical interface for user to adjust pmdCamServer settings.
 *
 * @section IFMcam IFMcam
 * @author Łukasz Ilnicki
 * @details ROS node. Obtain data from IFM sensor.
 *
 * @section IFMoffline IFMoffline {offline_data_file}
 * @author Łukasz Ilnicki
 * @details ROS node. Obtain data from sensor raw data file.
 *
 * @section Links Useful links
 * -# <a href="http://www.ros.org/wiki/">ROS documentation</a>
 * -# <a href="http://www.xmlrpc.com/">XML-RPC home page</a>
 * -# <a href=" http://www.pointclouds.org/">PCL - project home page</a>
 * -# <a href="http://docs.pointclouds.org/trunk/index.html">PCL reference</a>
 * -# <a href="http://opencv.itseez.com/index.html">OpenCV-2.3 documentation</a>
 * -# <a href="http://developer.qt.nokia.com/quarterly/view/using_cmake_to_build_qt_projects">Using CMake to Build Qt Projects</a>
 * -# <a href="http://doc.qt.nokia.com/4.7/index.html">Qt-4.7 reference documentation</a>
 */

/**
 * @page todo List of TODO
 * -# wczytywanie pliku z danymi kalibracji
 * -# wczytywanie pliku z danymi z sensora
 * -# nałożenie punktów z kamery web na chmurę 3D
 * -# własna siatka za pomocą marker triangle list
 * -# sprawdzanie połączenia z kamerą przez protokół TCP/IP
 * -# obliczanie unambiguous_range
 */

/**
  * @class pmdCam::msg::_image_box::image_box
  * @brief Automatically generated class from user-defined message type.
  *
  * @class pmdCam::msg::_pmd_settings::pmd_settings
  * @brief Automatically generated class from user-defined message type.
  */

/**
  * @bug pmdCamServer need to be shutdown before GUI shutdown
  */

#ifndef PMDCAM_H
#define	PMDCAM_H
#endif /* PMDCAM_H */
