////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014
//
// Modular Framework for OpenGLES2 rendering on multiple platforms.
//
namespace octet {
  /// Scene containing a box with octet.
  class water_waves : public app {
		//defines
		#define TWOPI 6.28185
		#define PI 3.141592
		#define HEIGHT 64
		#define WIDTH 64
		#define PADDEDHEIGHT HEIGHT+2
		#define PADDEDWIDTH WIDTH+2

		// scene for drawing box
		ref<visual_scene> app_scene;
		material *blue, *water;
		image *waterImg;

		//dynamic arrays
		dynarray<char> read;
		dynarray<char> waveLength;
		dynarray<char> smplitude;
		dynarray<char> speed;

  public:
    /// this is called when we construct the class before everything is initialised.
    water_waves(int argc, char **argv) : app(argc, argv) {
    }

    /// this is called once OpenGL is initialized
    void app_init() {
		app_scene =  new visual_scene();
		app_scene->create_default_camera_and_lights();
    }

    /// this is called to draw the world
    void draw_world(int x, int y, int w, int h) {
		int vx = 0, vy = 0;
		get_viewport_size(vx, vy);
		app_scene->begin_render(vx, vy);

		// update matrices. assume 30 fps.
		app_scene->update(1.0f/30);

		// draw the scene
		app_scene->render((float)vx / vy);
    }
  };
}
