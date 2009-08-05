/**
 * \file rendering.h
 * \brief Header file for the rendering
 * \author Vadim Tikhanoff
 * \date 2008
 * \note Release under GNU GPL v2.0
 **/


#include <ode/ode.h>
#include "VideoTexture.h"

#ifndef __RENDERING_H__
#define __RENDERING_H__

#define FLOOR  1
#define WOOD 2	
#define MARBLE 3
#define STEELOCEAN 4
#define STRESSEDTIN 5
#define METAL 6

extern unsigned int Texture[16];

void setup_opengl();
void DrawVideo(VideoTexture *video);
void DrawGround(bool wireframe);
void DrawBox(float length, float height, float width, bool wireframe, bool texture, int whichtexture);
void DrawSphere(float radius, bool wireframe, bool texture,int whichtexture);
void DrawCylinder(float radius, float length, bool wireframe, bool texture,int whichtexture);
void LDEsetM(const dReal *pos,const dReal *R);
GLuint LoadTextureRAW( const char * filename, int wrap );
void drawSkyDome(float x, float y, float z, float width, float height, float length);
//void CreateCylinder(dReal length, dReal radius);
#endif
