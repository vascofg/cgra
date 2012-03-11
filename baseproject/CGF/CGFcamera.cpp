#include <GL/glut.h>
#include "CGFcamera.h"

CGFcamera::CGFcamera()
{
	//float light0_pos[4] = {4.0, 6.0, 3.0, 1.0};
	position[0] = 0;
	position[1] = 0;
	position[2] = -25;

	rotation[0] = 0;
	rotation[1] = 0;
	rotation[2] = 0;

	target[0] = 0;
	target[1] = 0;
	target[2] = 0;

	setExamineMode();
}

CGFcamera::~CGFcamera()
{

}

bool CGFcamera::rotateTo(int axis, float angle, float increment)
{
	if (axis!=CG_CGFcamera_AXIS_X && axis!=CG_CGFcamera_AXIS_Y && axis!=CG_CGFcamera_AXIS_Z) return false;

	if(this->rotation[axis] < angle)
	{
		this->rotation[axis] += increment;
		return false;
	}
	return true;
}

bool CGFcamera::setRotation(int axis, float angle)
{
	if (axis!=CG_CGFcamera_AXIS_X && axis!=CG_CGFcamera_AXIS_Y && axis!=CG_CGFcamera_AXIS_Z) return false;
	this->rotation[axis] = angle;
	return true;
}

bool CGFcamera::rotate(int axis, float angle)
{
	if (axis!=CG_CGFcamera_AXIS_X && axis!=CG_CGFcamera_AXIS_Y && axis!=CG_CGFcamera_AXIS_Z) return false;
	this->rotation[axis] += angle;
	return true;
}

bool CGFcamera::moveTo(int axis, float value, float increment)
{
	if (axis!=CG_CGFcamera_AXIS_X && axis!=CG_CGFcamera_AXIS_Y && axis!=CG_CGFcamera_AXIS_Z) return false;

	if(this->position[axis] < value)
	{
		this->position[axis] += increment;
		return false;
	}
	return true;
}

bool CGFcamera::translate(int axis, float value)
{
	if (axis!=CG_CGFcamera_AXIS_X && axis!=CG_CGFcamera_AXIS_Y && axis!=CG_CGFcamera_AXIS_Z) return false;
	this->position[axis] += value;
	return true;
}

void CGFcamera::setX(float value)
{
	this->position[0] = value;
}

void CGFcamera::setY(float value)
{
	this->position[1] = value;
}

void CGFcamera::setZ(float value)
{
	this->position[2] = value;
}

void CGFcamera::setExamineMode()
{
	mode=EXAMINE_MODE;
}

void CGFcamera::setWalkMode()
{
	mode=WALK_MODE;
}

void CGFcamera::applyView()
{
	if (mode==EXAMINE_MODE)
	{
		glTranslatef(position[0],position[1], position[2]);
		// glTranslatef(0, 0, position[2]); // or this, if we ignore panning

		glRotatef(this->rotation[0], 1.f, 0.f, 0.f);
		glRotatef(this->rotation[1], 0.f, 1.f, 0.f);
		glRotatef(this->rotation[2], 0.f, 0.f, 1.f);

	}
	else
	{
		glRotatef(this->rotation[0], 1.f, 0.f, 0.f);
		glRotatef(this->rotation[1], 0.f, 1.f, 0.f);
		glRotatef(this->rotation[2], 0.f, 0.f, 1.f);

		glTranslatef(position[0], position[1], position[2]);
	}

}

