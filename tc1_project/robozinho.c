#include <GL/glut.h>
  
// Rotation

static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;


// Change viewing volume and viewport.  Called when window is resized  

void ChangeSize(int w, int h){  
    
    GLfloat fAspect;  
  
    // Prevent a divide by zero  
    if(h == 0) h = 1;  
  
    // Set Viewport to window dimensions  
    glViewport(0, 0, w, h);  
  
    fAspect = (GLfloat)w/(GLfloat)h;  
  
    // Reset coordinate system  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
  
    // Produce the perspective projection  
    gluPerspective(35.0f, fAspect, 1.0, 40.0);  
  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
}  
  

  
// This function does any needed initialization on the rendering context.  
// Here it sets up and initializes the lighting for the scene.  

void SetupRC(){  

    // Light values and coordinates  
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };  
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };  
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };  
  
    glEnable(GL_DEPTH_TEST);    // Hidden surface removal  
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out  
    glEnable(GL_CULL_FACE);     // Do not calculate inside  
  
    // Enable lighting  
    glEnable(GL_LIGHTING);  
  
    // Setup and enable light 0  
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);  
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);  
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);  
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);  
    glEnable(GL_LIGHT0);  
  
    // Enable color tracking  
    glEnable(GL_COLOR_MATERIAL);  
      
    // Set Material properties to follow glColor values  
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  
  
    // Black blue background  
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);  

}  
  
// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x, int y){  

    if(key == GLUT_KEY_LEFT) yRot -= 5.0f;  
  
    if(key == GLUT_KEY_RIGHT) yRot += 5.0f;    

    if(key == GLUT_KEY_UP) xRot += 5.0f;  
  
    if(key == GLUT_KEY_DOWN) xRot -= 5.0f;     

    xRot = (GLfloat)((const int) xRot % 360);
    yRot = (GLfloat)((const int) yRot % 360); 

    // Refresh the Window  
    glutPostRedisplay();  
}
  
// Called to draw scene  
void RenderScene(void){  

    GLUquadricObj *pObj;    // Quadric Object  
      
    // Clear the window with current clearing color  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
    // Save the matrix state and do the rotations  
    glPushMatrix();

	// Move object back and do in place rotation  
	glTranslatef(0.0f, -1.0f, -5.0f);  
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);  
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

	// Draw something  
	pObj = gluNewQuadric();  
	gluQuadricNormals(pObj, GLU_SMOOTH);  

    
    // head (white)
    glColor3f(1.0f, 1.0f, 1.0f); 	
	glPushMatrix(); 
		glTranslatef(0.0f, 1.4f, -0.13f);
        glRotatef(45,0, 0,  1);
		glutSolidCylinder( 0.24f, 0.3,4, 13);
	
	glPopMatrix();  
    // // pink
    glColor3f(1.0f, 0.2f, 0.5f); 	
	glPushMatrix(); 
		glTranslatef(0.0f, 1.4f, -0.15f);
        glRotatef(45,0, 0,  1);
		glutSolidCylinder( 0.3f, 0.3,4, 13);
	
	glPopMatrix();


	// eyes (black)
    glColor3f(0.0f, 0.0f, 0.0f); 
	glPushMatrix();
        
		glTranslatef(0.09f, 1.4f, 0.17f);
		gluSphere(pObj, 0.03f, 26, 13);  

	glPopMatrix(); 


    glColor3f(0.0f, 0.0f, 0.0f); 
	glPushMatrix();
        
		glTranslatef(-0.09f, 1.4f, 0.17);
		gluSphere(pObj, 0.03f, 26, 13);  

	glPopMatrix(); 


    // hairbrowns (brown)
    glColor3f(0.2f, 0.0f, 0.0f); 

 	glPushMatrix();
		glTranslatef(-0.12f, 1.5050, 0.17f);
        glRotatef(90,0.0,1,0);
        glRotatef(30,1.0,0,0);
		gluCylinder(pObj, 0.006f, 0.005f, 0.07f, 26, 13);  
	glPopMatrix(); 

    glPushMatrix();
		glTranslatef(0.055f, 1.465, 0.17f);
        glRotatef(-90,0.0,1,0);
        glRotatef(210,1.0,0,0);
		gluCylinder(pObj, 0.005f, 0.006f, 0.07f, 26, 13);  
	glPopMatrix();

    // mouth (brown)
    //glColor3f(0.2f, 0.0f, 0.0f); 

 	glPushMatrix();
		glTranslatef(0.0012f, 1.3, 0.17f);
        glRotatef(90,0.0,1,0);
        glRotatef(210,1.0,0,0);
		gluCylinder(pObj, 0.006f, 0.006f, 0.05f, 26, 13);  
	glPopMatrix(); 

    glPushMatrix();
		glTranslatef(0.044f, 1.325, 0.17f);
        glRotatef(-90,0.0,1,0);
        glRotatef(30,1.0,0,0);
		gluCylinder(pObj, 0.006f, 0.006f, 0.05f, 26, 13);  
	glPopMatrix();


    // antenas
    glColor3f(1.0f, 0.1f, 0.5f);  
    glPushMatrix(); 

        glTranslatef(-0.14f, 1.8f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.02f, 0.2f, 26, 1);  

    glPopMatrix();

    glPushMatrix(); 

        glTranslatef(0.14f, 1.8f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.02f, 0.2f, 26, 1);  

    glPopMatrix();


    // body (black)
	// // pescoço
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix(); 

        glTranslatef(0.0f, 1.2f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.08f, 0.1f, 26, 1);  

    glPopMatrix();

    glColor3f(1.0f, 0.2f, 0.5f); 
    // // mid section
    glPushMatrix(); 

        glTranslatef(0.0f, 1.1f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.3f, 0.6f, 4, 1);  

    glPopMatrix(); 
    // legs
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix(); 

        glTranslatef(-0.1f, 0.5f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.25f, 26, 1);  

    glPopMatrix();

    glPushMatrix(); 

        glTranslatef(0.1f, 0.5f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.25f, 26, 1);  

    glPopMatrix();
    //
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPushMatrix(); 

        glTranslatef(-0.1f, 0.24f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.25f, 26, 1);  

    glPopMatrix();

    glPushMatrix(); 

        glTranslatef(0.1f, 0.24f, 0.0f);
        glRotatef(90,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.25f, 26, 1);  

    glPopMatrix();
    //feet
    glPushMatrix(); 

        glTranslatef(0.1f, 0.02f, 0.0f);
        glRotatef(0,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.1f, 4, 1);  

    glPopMatrix();

    glPushMatrix(); 

        glTranslatef(-0.1f, 0.02f, 0.0f);
        glRotatef(0,1, 0,  0);
        glRotatef(45,0, 0,  1);
        
        glutSolidCylinder(0.05f, 0.1f, 4, 1);  

    glPopMatrix();

    // arms (brown)
    glColor3f(0.0f, 0.0f, 0.0f); 

    // // left arm 
 	glPushMatrix();
		glTranslatef(0.20f, 0.98, 0.1f);
        glRotatef(90,0.0,1,0);
        glRotatef(30,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.02f, 0.25f, 26, 13);  
	glPopMatrix(); 

    glPushMatrix();
		glTranslatef(0.41f, 0.86, 0.1f);
        glRotatef(90,0.0,1,0);
        glRotatef(70,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.02f, 0.25f, 26, 13);  
	glPopMatrix(); 


    // right arm (brown)
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
		glTranslatef(-0.20f, 0.98, 0.1f);
        glRotatef(-90,0.0,1,0);
        glRotatef(30,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.02f, 0.25f, 26, 13);  
	/*glPopMatrix(); 

    glPushMatrix();*/
		glTranslatef(0.0f, 0.0f, 0.25f);
        glRotatef(-80,1,0,0);
        //glRotatef(-45,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.02f, 0.25f, 26, 13);  
	glPopMatrix(); 

    // hands (still brown)
       

    // // right hands
	glPushMatrix();
		glTranslatef(-0.579f, 1.0357f, 0.1f);
        glRotatef(-90,0.0,1,0);
        glRotatef(-45,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	/*glPopMatrix();

    glPushMatrix();*/
		glTranslatef(0.0f, 0.0, 0.0f);
        glRotatef(-90,0.0,1,0);
        glRotatef(-120,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	/*glPopMatrix();

    glPushMatrix();*/
		glTranslatef(0.0, 0.0f, 0.0f);
        glRotatef(155,0.0,1,0);
        glRotatef(-40,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	glPopMatrix();

    // // left hands

    glPushMatrix();
		glTranslatef(0.495f, 0.63f, 0.1f);
        glRotatef(90,0.0,1,0);
        glRotatef(70,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	glPopMatrix();

    glPushMatrix();
		glTranslatef(0.495f, 0.63f, 0.1f);
        glRotatef(90,0.0,1,0);
        glRotatef(135,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	glPopMatrix();

    glPushMatrix();
		glTranslatef(0.495f, 0.63f, 0.1f);
        glRotatef(90,0.0,1,0);
        glRotatef(20,1.0,0,0);
		gluCylinder(pObj, 0.02f, 0.01f, 0.06f, 26, 13);  
	glPopMatrix();


    // Restore the matrix state  
    glPopMatrix();  
  
    // Buffer swap  
    glutSwapBuffers();  

}    

int main(int argc, char *argv[]){

    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
    glutInitWindowSize(800, 600);  
    glutCreateWindow("Modeling with Quadrics");  
    glutReshapeFunc(ChangeSize);  
    glutSpecialFunc(SpecialKeys);  
    glutDisplayFunc(RenderScene);  
    SetupRC();  
    glutMainLoop();  
      
    return 0; 
}