# manipulator_gazebo
Example of 6DoF manipulator simulation in gazebo

Kinematics & Dynamics of Robots - Academic Course

Ben Gurion University of the Negev

Mechanical Engineering Dept.

Nir Levi - nle@post.bgu.ac.il

Prerequisites:
===========================================
Install git:
------------ 
sudo apt-get install git-all

sudo apt-get install kdiff3

sudo apt-get install qgit 

Install gazebo add-on:
------------
sudo apt-get install ros-indigo-move-base

sudo apt-get install ros-indigo-ros-control ros-indigo-ros-controllers

sudo apt-get install ros-indigo-gazebo-ros-control

Install this package in your catkin_ws
------------
(in a new terminal window)

"cd ~/catkin_ws/src"

"git clone https://github.com/nirlevi5/manipulator_gazebo.git"

"cd .."

"catkin_make"


Launching The Manipulator In GAZEBO Simulator:
===========================================
(in a new terminal window)
"roslaunch manipulator_gazebo manipulator_empty_world.launch"

(in a new terminal window)
"rqt"

--> plugins --> topics --> Message Publisher

--> plugins --> topics --> Topic Monitor




