#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

attribute vec4 vPosition;

void main(void)
{
    gl_Position = vPosition;
}
