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
    GLfloat  lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };  
  
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

    
    // muralhas

    glColor3f(1.0f, 1.0f, 1.0f);
    
    
    glColor3f(1.0f, 0.0f, 0.20f);
    glColor3f(0.90f, 0.5f, 0.3f); 
    glPushMatrix();
            glTranslatef(-1.05, 0.14, 1.2f);
            glRotatef(90,0, 1,  0);
            glRotatef(45,0, 0,  1);
            gluCylinder(pObj, 0.2f, 0.2f, 2.1f, 4, 1);    
    glPopMatrix();

    glPushMatrix();
            glTranslatef(-1.2, 0.14, 1.2f);
            glRotatef(180,0, 1,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.2f, 2.4f, 4, 1);  
    glPopMatrix();

    glPushMatrix();
            glTranslatef(-1.05, 0.14, -1.2f);
            glRotatef(90,0, 1,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.2f, 2.1f, 4, 1);  
    glPopMatrix();

    glPushMatrix();
            glTranslatef(1.2, 0.14, -1.3f);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.2f, 2.4f, 4, 1);  
    glPopMatrix();

    

    //torres
	glPushMatrix();
		glTranslatef(-1.2f, 0.0, 1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.25f, 0.7f, 26, 13);  
	glPopMatrix();  
 
	glPushMatrix();
		glTranslatef(1.2f, 0.0, 1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.25f, 0.7f, 26, 13);  
	glPopMatrix(); 
	glPushMatrix();
		glTranslatef(-1.2f, 0.0, -1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.25f, 0.7f, 26, 13);  
	glPopMatrix(); 

    // // torre quadrada
    glPushMatrix();
            glTranslatef(1.2f, 0.0, -1.2f);
            glRotatef(-90,1.0, 0,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.28f, 0.9f, 4, 1);  
        glPopMatrix();

    // torre entrada quadrada

    
    glPushMatrix();
            glTranslatef(0.0f, 0.0, 1.2f);
            glRotatef(-90,1.0, 0,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.28f, 0.4f, 4, 1);  
    glPopMatrix();

    
    // portao torre entrada
    glColor3f(0.4f, 0.20f, 0.0f); 
    glPushMatrix();
            glTranslatef(0.0f, 0.0, 1.33f);
            glRotatef(-90,1.0, 0,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.13f, 0.3f, 4, 1);  
    glPopMatrix();

    glPushMatrix();
            glTranslatef(0.0f, 0.0, 1.06f);
            glRotatef(-90,1.0, 0,  0);
            glRotatef(45,0, 0,  1);
            glutSolidCylinder(0.13f, 0.3f, 4, 1);  
    glPopMatrix();
    glColor3f(0.90f, 0.5f, 0.3f); 

    //telhas torres:
    
    glColor3f(0.90f, 0.5f, 0.3f); 
    glPushMatrix();
            glTranslatef(1.0f, 1.015, -1.2f);
            glRotatef(90,0, 0,  1);
            glRotatef(90,1, 0,  0);
            glutSolidCylinder(0.23f, 0.399f, 3, 1);  
    glPopMatrix();
    glColor3f(0.9f, 0.1f, 0.1f); 
    float lugar_telha_torre = -1.2f;
    for(int i = 0;i<2;i++){
        glPushMatrix();
            glTranslatef(lugar_telha_torre, 0.7f, 1.2f);
            glRotatef(-90,1.0,0,0);
            gluCylinder(pObj, 0.27f, 0.0f, 0.6f, 26, 13);  
        glPopMatrix(); 
        lugar_telha_torre = lugar_telha_torre+2.4;
    }
   
    glPushMatrix();
        glTranslatef(-1.2, 0.7f, -1.2);
        glRotatef(-90,1.0,0,0);
        gluCylinder(pObj, 0.27f, 0.0f, 0.6f, 26, 13);  
    glPopMatrix(); 

    //telha torre entrada:
    glColor3f(0.9f, 0.1f, 0.1f); 
    glPushMatrix();
            glTranslatef(0.0f, 0.512, 1.0f);
            glRotatef(90,0, 0,  1);
            //glRotatef(-90,1, 0,  0);
            glutSolidCylinder(0.25f, 0.399f, 3, 1);  
    glPopMatrix();

    //telhas muralhas:
    /*
    glPushMatrix();
            glTranslatef(-1.2f, 0.512, 1.2f);
            glRotatef(90,0, 0,  1);
            glRotatef(90,1, 0,  0);
            glutSolidCylinder(0.03f, 1.0f, 4, 1);  
    glPopMatrix();
    
    glColor3f(0.5f, 0.1f, 0.0f); 
    glPushMatrix();
        glTranslatef(1.2, 0.9f, -1.3);
        glRotatef(-90,1.0,0,0);
        gluCylinder(pObj, 0.33f, 0.0f, 0.6f, 26, 13);  
    glPopMatrix(); 
    */

    // haste das telhas das torres
    glPushMatrix();
		glTranslatef(-1.2f, 1.15, -1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.01f, 0.2f, 4, 13);  
	glPopMatrix(); 
    
    glPushMatrix();
		glTranslatef(-1.2f, 1.15, 1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.01f, 0.2f, 4, 13);  
	glPopMatrix();

    glPushMatrix();
		glTranslatef(1.2f, 1.15, 1.2f);
        glRotatef(-90,1.0,0,0);
		glutSolidCylinder(0.01f, 0.2f, 4, 13);  
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