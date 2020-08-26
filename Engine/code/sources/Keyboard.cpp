#include "Keyboard.hpp"
#include <SDL.h>

namespace Engine
{
	Keyboard::Key Keyboard::translate_sdl_key(int sdl_key)
	{
        switch (sdl_key)
        {

        case SDLK_a:      return A;
        case SDLK_b:      return B;
        case SDLK_c:      return C;
        case SDLK_d:      return D;
        case SDLK_e:      return E;
        case SDLK_f:      return F;
        case SDLK_g:      return G;
        case SDLK_h:      return H;
        case SDLK_i:      return I;
        case SDLK_j:      return J;
        case SDLK_k:      return K;
        case SDLK_l:      return L;
        case SDLK_m:      return M;
        case SDLK_n:      return N;
        case SDLK_o:      return O;
        case SDLK_p:      return P;
        case SDLK_q:      return Q;
        case SDLK_r:      return R;
        case SDLK_s:      return S;
        case SDLK_t:      return T;
        case SDLK_u:      return U;
        case SDLK_v:      return V;
        case SDLK_w:      return W;
        case SDLK_x:      return X;
        case SDLK_y:      return Y;
        case SDLK_z:      return Z;

        case SDLK_SPACE:  return SPACE;

        case SDLK_0:      return K0;
        case SDLK_1:      return K1;
        case SDLK_2:      return K2;
        case SDLK_3:      return K3;
        case SDLK_4:      return K4;
        case SDLK_5:      return K5;
        case SDLK_6:      return K6;
        case SDLK_7:      return K7;
        case SDLK_8:      return K8;
        case SDLK_9:      return K9;

        }

        return {};
	}
}