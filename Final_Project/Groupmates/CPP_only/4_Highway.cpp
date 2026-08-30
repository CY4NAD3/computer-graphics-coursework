// Object ID Reference Table
// ITEM-01 : Water
// ITEM-02 : Waves
// ITEM-03 : Boat
// ITEM-04 : Cloud 1
// ITEM-05 : Cloud 2
// ITEM-06 : Cloud 3
// ITEM-07 : Hill 1
// ITEM-08 : Hill 2
// ITEM-09 : Hill 3
// ITEM-10 : Hill 4
// ITEM-11 : Road
// ITEM-12 : Bridge
// ITEM-13 : Road Markings
// ITEM-14 : Tree 1
// ITEM-15 : Tree 2
// ITEM-16 : Tree 3
// ITEM-17 : Tree 4
// ITEM-18 : Street Lamp 1
// ITEM-19 : Street Lamp 2
// ITEM-20 : Street Lamp 3
// ITEM-21 : Street Lamp 4
// ITEM-22 : Highway Sign 1
// ITEM-23 : Highway Sign 2
// ITEM-24 : Car 1
// ITEM-25 : Car 2
// ITEM-26 : Car 3
// ITEM-27 : Bus

// Animation Function ID Reference Table
// FUNC-01 : init()
// FUNC-02 : updateBackground()
// FUNC-03 : drawWater()
// FUNC-04 : drawCircle()
// FUNC-05 : drawClouds()
// FUNC-06 : drawHills()
// FUNC-07 : drawRoadAndBridge()
// FUNC-08 : drawTrees()
// FUNC-09 : drawLamps()
// FUNC-10 : drawHighwaySigns()
// FUNC-11 : drawCustomCar()
// FUNC-12 : drawBus()
// FUNC-13 : display()
// FUNC-14 : update()
// FUNC-15 : handleKeypress()
// FUNC-16 : handleMouse()
// FUNC-17 : main()

#include <windows.h>
#include <GL/glut.h>
#include <math.h>


float carX1 = -15.0f;
float carX2 = -45.0f;
float carX3 = -75.0f;
float busX = -30.0f;
float cloudX = 0.0f;
float boatX = -25.0f;
float waveX = 0.0f;

float wheelAngle = 0.0f;
float speed = 0.04f;
float savedSpeed = 0.04f;
bool isAnimating = true;


int currentScene = 0;
bool vehicleMoving = true;
int timeState = 1;
bool lightsOn = false;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}


void updateBackground()
{
	if (timeState == 0)
		glClearColor(1.0f, 0.6f, 0.4f, 1.0f);
	else if (timeState == 1)
		glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
	else if (timeState == 2)
		glClearColor(0.9f, 0.4f, 0.2f, 1.0f);
	else if (timeState == 3)
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
}

void drawWater()
{

	glColor3ub(135, 206, 250);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(100, 0);
		glVertex2f(100, 35);
		glVertex2f(0, 35);
	glEnd();


	glPushMatrix();
		glTranslatef(waveX, 0.0f, 0.0f);

		glColor3ub(255, 255, 255);
		glLineWidth(1.5f);


		glBegin(GL_LINE_STRIP);
			glVertex2f(20.0f, 26.0f);
			glVertex2f(21.5f, 26.8f);
			glVertex2f(23.0f, 26.0f);
			glVertex2f(24.5f, 26.8f);
			glVertex2f(26.0f, 26.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(55.0f, 25.0f);
			glVertex2f(56.5f, 25.8f);
			glVertex2f(58.0f, 25.0f);
			glVertex2f(59.5f, 25.8f);
			glVertex2f(61.0f, 25.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(35.0f, 16.0f);
			glVertex2f(36.5f, 16.8f);
			glVertex2f(38.0f, 16.0f);
			glVertex2f(39.5f, 16.8f);
			glVertex2f(41.0f, 16.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(12.0f, 11.0f);
			glVertex2f(13.5f, 11.8f);
			glVertex2f(15.0f, 11.0f);
			glVertex2f(16.5f, 11.8f);
			glVertex2f(18.0f, 11.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(72.0f, 11.0f);
			glVertex2f(73.5f, 11.8f);
			glVertex2f(75.0f, 11.0f);
			glVertex2f(76.5f, 11.8f);
			glVertex2f(78.0f, 11.0f);
		glEnd();

	glPopMatrix();


	glPushMatrix();
		glTranslatef(boatX, 0.0f, 0.0f);


		glColor3ub(255, 255, 255);
		glLineWidth(1.5f);
		glBegin(GL_LINE_STRIP);
			glVertex2f(14.0f, 12.5f);
			glVertex2f(15.5f, 13.3f);
			glVertex2f(17.0f, 12.5f);
			glVertex2f(18.5f, 13.3f);
			glVertex2f(20.0f, 12.5f);
		glEnd();


		glColor3ub(160, 82, 45);
		glBegin(GL_QUADS);
			glVertex2f(13.0f, 18.0f);
			glVertex2f(21.0f, 18.0f);
			glVertex2f(19.0f, 14.0f);
			glVertex2f(15.0f, 14.0f);
		glEnd();


		glColor3ub(80, 40, 20);
		glLineWidth(2.5f);
		glBegin(GL_LINES);
			glVertex2f(17.0f, 18.0f);
			glVertex2f(17.0f, 25.0f);
		glEnd();


		glColor3ub(255, 255, 255);
		glBegin(GL_TRIANGLES);
			glVertex2f(17.2f, 24.5f);
			glVertex2f(17.2f, 19.0f);
			glVertex2f(21.5f, 21.5f);
		glEnd();

	glPopMatrix();
}

void drawCircle(float cx, float cy, float r)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < 30; i++)
	{
		float angle = (i * 2.0f * 3.1416f) / 30;
		glVertex2f(cx + (r * cos(angle)), cy + (r * sin(angle)));
	}
	glEnd();
}

void drawClouds(float offsetX)
{
	glPushMatrix();
		glTranslatef(offsetX, 0.0f, 0.0f);

		glColor3ub(255, 255, 255);


		drawCircle(18.0f, 82.0f, 2.5f);
		drawCircle(20.5f, 83.0f, 3.0f);
		drawCircle(23.0f, 82.0f, 2.6f);
		drawCircle(20.5f, 80.8f, 2.3f);


		drawCircle(47.0f, 76.0f, 2.5f);
		drawCircle(49.5f, 77.0f, 3.0f);
		drawCircle(52.0f, 76.0f, 2.6f);
		drawCircle(49.5f, 74.8f, 2.3f);


		drawCircle(75.0f, 83.0f, 2.5f);
		drawCircle(77.5f, 84.0f, 3.0f);
		drawCircle(80.0f, 83.0f, 2.6f);
		drawCircle(77.5f, 81.8f, 2.3f);

	glPopMatrix();
}

void drawHills()
{
	glBegin(GL_TRIANGLES);
		glColor3ub(80, 140, 55);
		glVertex2f(-20, 35);
		glVertex2f(40, 35);
		glVertex2f(10, 70);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(90, 150, 60);
		glVertex2f(20, 35);
		glVertex2f(70, 35);
		glVertex2f(45, 80);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(75, 130, 50);
		glVertex2f(50, 35);
		glVertex2f(100, 35);
		glVertex2f(75, 65);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(85, 145, 58);
		glVertex2f(75, 35);
		glVertex2f(120, 35);
		glVertex2f(95, 75);
	glEnd();
}

void drawRoadAndBridge()
{
	glColor3ub(50, 50, 55);
	glBegin(GL_QUADS);
		glVertex2f(0, 35);
		glVertex2f(35, 35);
		glVertex2f(35, 45);
		glVertex2f(0, 45);

		glVertex2f(65, 35);
		glVertex2f(100, 35);
		glVertex2f(100, 45);
		glVertex2f(65, 45);
	glEnd();

	glColor3ub(180, 50, 40);
	glBegin(GL_QUADS);
		glVertex2f(35, 34);
		glVertex2f(65, 34);
		glVertex2f(65, 46);
		glVertex2f(35, 46);
	glEnd();

	glColor3ub(65, 65, 70);
	glBegin(GL_QUADS);
		glVertex2f(35, 36);
		glVertex2f(65, 36);
		glVertex2f(65, 44);
		glVertex2f(35, 44);
	glEnd();

	glColor3ub(220, 220, 220);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(0, 45);
		glVertex2f(100, 45);
		glVertex2f(0, 35);
		glVertex2f(100, 35);
	glEnd();

	glColor3ub(255, 215, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(0, 40);
		glVertex2f(4, 40);
		glVertex2f(8, 40);
		glVertex2f(12, 40);
		glVertex2f(16, 40);
		glVertex2f(20, 40);
		glVertex2f(24, 40);
		glVertex2f(28, 40);
		glVertex2f(32, 40);
		glVertex2f(36, 40);
		glVertex2f(40, 40);
		glVertex2f(44, 40);
		glVertex2f(48, 40);
		glVertex2f(52, 40);
		glVertex2f(56, 40);
		glVertex2f(60, 40);
		glVertex2f(64, 40);
		glVertex2f(68, 40);
		glVertex2f(72, 40);
		glVertex2f(76, 40);
		glVertex2f(80, 40);
		glVertex2f(84, 40);
		glVertex2f(88, 40);
		glVertex2f(92, 40);
		glVertex2f(96, 40);
		glVertex2f(100, 40);
	glEnd();

	glColor3ub(220, 40, 30);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(35, 48);
		glVertex2f(65, 48);
		glVertex2f(35, 32);
		glVertex2f(65, 32);
	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(35, 44);
		glVertex2f(35, 48);
		glVertex2f(38, 44);
		glVertex2f(38, 48);
		glVertex2f(41, 44);
		glVertex2f(41, 48);
		glVertex2f(44, 44);
		glVertex2f(44, 48);
		glVertex2f(47, 44);
		glVertex2f(47, 48);
		glVertex2f(50, 44);
		glVertex2f(50, 48);
		glVertex2f(53, 44);
		glVertex2f(53, 48);
		glVertex2f(56, 44);
		glVertex2f(56, 48);
		glVertex2f(59, 44);
		glVertex2f(59, 48);
		glVertex2f(62, 44);
		glVertex2f(62, 48);
		glVertex2f(65, 44);
		glVertex2f(65, 48);
		glVertex2f(35, 32);
		glVertex2f(35, 36);
		glVertex2f(38, 32);
		glVertex2f(38, 36);
		glVertex2f(41, 32);
		glVertex2f(41, 36);
		glVertex2f(44, 32);
		glVertex2f(44, 36);
		glVertex2f(47, 32);
		glVertex2f(47, 36);
		glVertex2f(50, 32);
		glVertex2f(50, 36);
		glVertex2f(53, 32);
		glVertex2f(53, 36);
		glVertex2f(56, 32);
		glVertex2f(56, 36);
		glVertex2f(59, 32);
		glVertex2f(59, 36);
		glVertex2f(62, 32);
		glVertex2f(62, 36);
		glVertex2f(65, 32);
		glVertex2f(65, 36);
	glEnd();
}

void drawTrees()
{
	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(4, 45);
		glVertex2f(6, 45);
		glVertex2f(6, 53);
		glVertex2f(4, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(1, 51);
		glVertex2f(9, 51);
		glVertex2f(5, 58);
    glEnd();
		glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(2, 54);
		glVertex2f(8, 54);
		glVertex2f(5, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(24, 45);
		glVertex2f(26, 45);
		glVertex2f(26, 53);
		glVertex2f(24, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(21, 51);
		glVertex2f(29, 51);
		glVertex2f(25, 58);
    glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(22, 54);
		glVertex2f(28, 54);
		glVertex2f(25, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(71, 45);
		glVertex2f(73, 45);
		glVertex2f(73, 53);
		glVertex2f(71, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(68, 51);
		glVertex2f(76, 51);
		glVertex2f(72, 58);
		glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(69, 54);
		glVertex2f(75, 54);
		glVertex2f(72, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(91, 45);
		glVertex2f(93, 45);
		glVertex2f(93, 53);
		glVertex2f(91, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(88, 51);
		glVertex2f(96, 51);
		glVertex2f(92, 58);
    glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(89, 54);
		glVertex2f(95, 54);
		glVertex2f(92, 61);
	glEnd();
}

void drawLamps()
{
	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(12, 45);
		glVertex2f(12, 55);
		glVertex2f(12, 55);
		glVertex2f(14, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(14, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(28, 45);
		glVertex2f(28, 55);
		glVertex2f(28, 55);
		glVertex2f(30, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(30, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(72, 45);
		glVertex2f(72, 55);
		glVertex2f(72, 55);
		glVertex2f(74, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(74, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(88, 45);
		glVertex2f(88, 55);
		glVertex2f(88, 55);
		glVertex2f(90, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(90, 54.5f);
	glEnd();
}

void drawHighwaySigns()
{
	glColor3ub(60, 60, 60);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(18, 45);
		glVertex2f(18, 51);
	glEnd();

	glColor3ub(0, 100, 190);
	glBegin(GL_QUADS);
		glVertex2f(15, 51);
		glVertex2f(21, 51);
		glVertex2f(21, 55);
		glVertex2f(15, 55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(15, 51);
		glVertex2f(21, 51);
		glVertex2f(21, 55);
		glVertex2f(15, 55);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(16.2f, 52.7f);
		glVertex2f(18.8f, 52.7f);
		glVertex2f(18.8f, 53.3f);
		glVertex2f(16.2f, 53.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(18.8f, 52.2f);
		glVertex2f(18.8f, 53.8f);
		glVertex2f(20.0f, 53.0f);
	glEnd();

	glColor3ub(60, 60, 60);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(82, 45);
		glVertex2f(82, 51);
	glEnd();

	glColor3ub(20, 130, 60);
	glBegin(GL_QUADS);
		glVertex2f(79, 51);
		glVertex2f(85, 51);
		glVertex2f(85, 55);
		glVertex2f(79, 55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(79, 51);
		glVertex2f(85, 51);
		glVertex2f(85, 55);
		glVertex2f(79, 55);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(80.2, 52.7);
		glVertex2f(82.8, 52.7);
		glVertex2f(82.8, 53.3);
		glVertex2f(80.2, 53.3);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(82.8f, 52.2f);
		glVertex2f(82.8f, 53.8f);
		glVertex2f(84.0f, 53.0f);
	glEnd();
}

void drawCustomCar(float posX, unsigned char r1, unsigned char g1, unsigned char b1, unsigned char r2, unsigned char g2, unsigned char b2)
{
	glPushMatrix();
		glTranslatef(posX, 36.0f, 0.0f);
		glScalef(0.5f, 0.5f, 1.0f);

		// Car Body Base
		glBegin(GL_QUADS);
			glColor3ub(r1, g1, b1);
			glVertex2f(2, 3.5);
			glVertex2f(12, 3.5);
			glVertex2f(11.5, 6);
			glVertex2f(2.5, 6);
		glEnd();

		// Car Top Roof Cabin
		glBegin(GL_QUADS);
			glColor3ub(r2, g2, b2);
			glVertex2f(4.5, 6);
			glVertex2f(9.5, 6);
			glVertex2f(8.5, 8.5);
			glVertex2f(5.5, 8.5);
		glEnd();

		// Windows
		glBegin(GL_TRIANGLES);
			glColor3ub(200, 204, 232);
			glVertex2f(4.8, 6.2);
			glVertex2f(5.7, 6.2);
			glVertex2f(5.7, 8.2);
		glEnd();

		glBegin(GL_QUADS);
			glColor3ub(200, 204, 232);
			glVertex2f(6, 6.2);
			glVertex2f(8, 6.2);
			glVertex2f(8, 8.2);
			glVertex2f(6, 8.2);
		glEnd();

		glBegin(GL_TRIANGLES);
			glColor3ub(200, 204, 232);
			glVertex2f(8.3, 6.2);
			glVertex2f(9.2, 6.2);
			glVertex2f(8.3, 8.2);
		glEnd();

		// Headlight (Toggled by 'B')
		if (lightsOn)
		{
			glColor3ub(255, 255, 0);
			glBegin(GL_QUADS);
				glVertex2f(12, 5);
				glVertex2f(12.5, 5);
				glVertex2f(12.5, 5.6);
				glVertex2f(12, 5.6);
			glEnd();
		}
		else
		{
			glBegin(GL_QUADS);
				glColor3ub(247, 203, 114);
				glVertex2f(12, 5);
				glVertex2f(11.3, 5);
				glVertex2f(11.2, 5.6);
				glVertex2f(11.7, 5.6);
			glEnd();
		}

		// Wheel 1
		{
			float radius = 1.2f;
			float xc = 4.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}

		// Wheel 2
		{
			float radius = 1.2f;
			float xc = 9.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();
}

void drawBus(float posX)
{
	glPushMatrix();
		glTranslatef(posX, 36.0f, 0.0f);
		glScalef(0.7f, 0.7f, 1.0f);

		// 1. Bus Main Body (Green)
		glColor3f(0.2f, 0.6f, 0.3f);
		glBegin(GL_QUADS);
			glVertex2f(2.0, 3.5);
			glVertex2f(16.0, 3.5);
			glVertex2f(16.0, 9.5);
			glVertex2f(2.0, 9.5);
		glEnd();

		// 2. Windows on the Bus
		glColor3f(0.85f, 0.95f, 1.0f);

		// Window 1
		glBegin(GL_QUADS);
			glVertex2f(3.5, 6.0);
			glVertex2f(6.0, 6.0f);
			glVertex2f(6.0, 9.0);
			glVertex2f(3.5, 9.0);
		glEnd();

		// Window 2
		glBegin(GL_QUADS);
			glVertex2f(7.5, 6.0);
			glVertex2f(10.0, 6.0);
			glVertex2f(10.0, 9.0);
			glVertex2f(7.5, 9.0);
		glEnd();

		// Window 3
		glBegin(GL_QUADS);
			glVertex2f(11.5, 6.0);
			glVertex2f(14.0, 6.0);
			glVertex2f(14.0, 9.0);
			glVertex2f(11.5, 9.0);
		glEnd();

		// 3. Headlight
		if (lightsOn)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
		}
		else
		{
			glColor3f(1.0f, 0.9f, 0.4f);
		}
		glBegin(GL_QUADS);
			glVertex2f(16.0f, 4.5f);
			glVertex2f(16.5f, 4.5f);
			glVertex2f(16.5f, 6.0f);
			glVertex2f(16.0f, 6.0f);
		glEnd();

		// 4. Wheel 1
		{
			float radius = 1.2f;
			float xc = 4.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}

		// 5. Wheel 2
		{
			float radius = 1.2f;
			float xc = 13.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();
}

void display()
{
	updateBackground();
	glClear(GL_COLOR_BUFFER_BIT);

	if (currentScene == 0)
	{
		drawWater();
		drawClouds(cloudX);
		drawHills();
		drawRoadAndBridge();
		drawTrees();
		drawLamps();
		drawHighwaySigns();

		drawBus(busX);

		drawCustomCar(carX1, 215, 181, 232, 211, 148, 242);
		drawCustomCar(carX2, 230, 50, 50, 200, 30, 30);
		drawCustomCar(carX3, 100, 180, 255, 70, 150, 235);
	}
	else if (currentScene == 1)
	{
		drawHills();
		drawRoadAndBridge();
		drawTrees();
		drawLamps();
		drawCustomCar(carX1, 50, 200, 50, 30, 150, 30);
		drawCustomCar(carX3, 50, 100, 250, 30, 70, 180);
	}

	glutSwapBuffers();
}

void update(int value)
{
	if (vehicleMoving)
	{
		carX1 += speed;
		carX2 += speed;
		carX3 += speed;
		busX  += speed;
		cloudX += (speed * 0.25f);
		boatX  += (speed * 0.5f);
		waveX  += (speed * 0.2f);

		wheelAngle -= (speed * 100.0f);
		if (wheelAngle < -360.0f)
		{
			wheelAngle += 360.0f;
		}
	}

	if (carX1 > 110.0f) carX1 = -15.0f;
	if (carX2 > 110.0f) carX2 = -15.0f;
	if (carX3 > 110.0f) carX3 = -15.0f;
	if (busX > 110.0f)  busX  = -30.0f;
	if (cloudX > 110.0f) cloudX = -90.0f;
	if (boatX > 110.0f)  boatX  = -25.0f;
	if (waveX > 100.0f)  waveX  = 0.0f;

	glutPostRedisplay();
	glutTimerFunc(16, update, 0);
}


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'c': // C: next scene, looping back to Village
		case 'C':
			currentScene = (currentScene + 1) % 2;
			break;

		case 'o': // O: vehicle control move
		case 'O':
			vehicleMoving = true;
			break;

		case 'p': // P: vehicle control stop
		case 'P':
			vehicleMoving = false;
			break;

		case 'z': // Z: Dawn
		case 'Z':
			timeState = 0;
			break;

		case 'x': // X: Day
		case 'X':
			timeState = 1;
			break;

		case 'v': // V: Night
		case 'V':
			timeState = 3;
			break;

		case 'b': // B: toggle lights on/off
		case 'B':
			lightsOn = !lightsOn;
			break;
	}
	glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (isAnimating)
		{
			savedSpeed = speed;
			speed = 0.0f;
			isAnimating = false;
		}
		else
		{
			speed = savedSpeed;
			isAnimating = true;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		boatX = -25.0f;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Scene with Keyboard and Mouse Interactivity");

	init();

	glutDisplayFunc(display);
	glutTimerFunc(0, update, 0);
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMouse);

	glutMainLoop();
	return 0;
}
