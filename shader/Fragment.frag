#version 150

#define PI 3.14159265359
#define TWO_PI 6.28318530718
const int shapeNum = 20;

uniform vec2 resolution;
uniform float time;

uniform vec2 positions[shapeNum];
uniform float circleWidth[shapeNum];
uniform float radius[shapeNum];
uniform vec3 circleColors[shapeNum];
uniform sampler2DRect fbo;

vec3 color;
out vec4 outputColor;


float sdCircle(vec2 p,float r){
  return length(p)-r;
}

float circle(vec2 p,float r){
  float d = sdCircle(p,r);
  float m = 1.0-smoothstep(0.01, 0.03, d);
  return m;
}

void main() {
  vec2 center = (gl_FragCoord.xy*2.0-resolution)/min(resolution.x,resolution.y);

  for(int i = 0; i < shapeNum; i++){
    float r = radius[i];
    vec2 pos = positions[i] / min(resolution.x,resolution.y);
    vec2 p = pos-center;
    color += vec3(circle(p,r+circleWidth[i])-circle(p,r)) * circleColors[i];
  }
  vec4 fboValue = texture(fbo, vec2(gl_FragCoord.x, gl_FragCoord.y));

  outputColor = vec4(color,1.0) + fboValue * 0.9;
}
