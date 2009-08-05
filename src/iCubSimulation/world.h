// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/**
 * \file world.h
 * \brief Header for the world creation
 * \author Vadim Tikhanoff
 * \date 2007
 * \note Release under GNU GPL v2.0
 **/

#pragma once
#include "SDL.h"
#include "SDL_opengl.h"
#include "rendering.h" 
#include <ode/ode.h>
#ifdef _MSC_VER
#pragma warning(disable:4244 4305)  // for VC++, no precision loss complaints
#endif 

using namespace yarp::os;

class worldSimData{ 
public:	
	#define MAXNUM 100
	#define GPB 3// maximum number of geometries per body
	double l_massobj0;
	double l_massobj1;
	double l_massobj2;
	double l_massobj3;
	
	int OBJNUM;
	int waitOBJ;
	int S_OBJNUM;
	
	int cylOBJNUM;
	int waitOBJ1;
	int S_cylOBJNUM;
	
	dReal color[100][3];
	dReal s_color[100][3];
	dReal color1[100][3];
	dReal s_color1[100][3];
	worldSimData();
};

class worldSim : public worldSimData {
public:
	static const bool textured = true;
	ConstString actWorld;
			// max number of objects
#define numObjJoints 5 //define Joints

	dJointID joint	[numObjJoints];
	dReal	 speed [numObjJoints];
	dJointID j;

	dBodyID tableBody[5];
	dGeomID tableGeom[5];

	dBodyID ballBody;
	dGeomID ballGeom;

	//init. encapsulated object - the Box
	dGeomID box_part[14];
	dGeomID box_geom[14];
	dBodyID Box;

	//Geometry group for the bodies of the Object
	dSpaceID boxObj;

	dBodyID box;
	dGeomID boxgeom;
	
struct MyObject {
  dBodyID boxbody;			// the body
  dGeomID geom[GPB];		// geometries representing this body
  dReal size[3];
};

 MyObject obj[MAXNUM];
 MyObject s_obj[MAXNUM];

 struct MyObject1 {
  dBodyID cylbody;			// the body
  dGeomID cylgeom[GPB];		// geometries representing this body
  dReal radius;
  dReal lenght;
};

 MyObject1 cyl_obj[MAXNUM];
 MyObject1 s_cyl_obj[MAXNUM];

public:

	void resetSpeeds();
	void setJointSpeeds();
	void syncAngles();
	void ballDamping();
	void draw();
	void drawGeom(dGeomID g, const dReal *pos, const dReal *rot);//, float red  = 0.0f, float green = 128.5f, float blue = 255.0f);
    void setPosition(dReal agent1X, dReal agent1Z, dReal agent1Y );
	void activateWorld();
	void init( dWorldID world, dSpaceID space, dReal X, dReal Y, dReal Z );

	~worldSim();

	worldSim(dWorldID world, dSpaceID space, dReal X, dReal Y, dReal Z);
};
