CMake Experimental Test Project
===

Experimental project to "bottom out" all the questions I have about how to make a multi-platform, header-only C project as part of a Maven Java project. CMake is the limiting factor - I'm learning it now. 

Proposal is that there's a "native" area invoked by the [cmake-maken-plugin](https://github.com/cmake-maven-project/cmake-maven-project), and a C dev would live in there or link across to it. One day, the CMake world may split off and become its own thing, but we'd need to get the interfaces solid first otherwise we descend into tightly-coupled release hell.
