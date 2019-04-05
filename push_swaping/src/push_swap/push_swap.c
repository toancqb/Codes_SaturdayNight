/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:08:02 by qtran             #+#    #+#             */
/*   Updated: 2019/02/28 19:08:03 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_lib_push_swap.h"

/*
gcc push_swap.c ft_pb.c ft_pa.c ft_init.c process.c ft_select.c
../tools/.c ../checker/ft_process_input.c ../checker/ft_display_checker.c
../../libft/libft.a
*/

void printf_ps(t_st *st) //
{
  int i;

  if (st_is_empty(st) == 0)
  {
    i = st->top;
    while (i >= st->bot)
    {
      printf("(%d)\n", st->tab[in(i)]);
      i--;
    }
  }
  printf("\n=--=\n");
}


int *ft_process_input_push_old(int argc, char **argv, int *len)
{
  char **tab;
  int i;
  int *input;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    while (i < *len && tab[i])
    {
      input[i] = (int)ft_atoi(tab[i]);
      i++;
    }
    return (input);
  }
  else
    ft_error();
  return (NULL);
}

int *ft_process_input_push(int argc, char **argv, int *len)
{
  char **tab;
  int i;
  int *input;

  *len = 0;
  if (argc >= 2)
  {
    tab = ft_strsplit(argv[1], ' ');
    while (tab[*len] != NULL)
      (*len)++;
    input = (int*)malloc(sizeof(int) * (*len));
    i = 0;
    while (i < *len && tab[i])
    {
      input[i] = (int)ft_atoi(tab[i]);
      i++;
    }
    return (input);
  }
  else
    ft_error();
  return (NULL);
}

int *ft_process_input_push_direct(int argc, char **argv, int *len)
{
  int i;
  int *input;
  int tmp[] = {
  361, 380, 345, 185, 237, 69, 486, 10, 304, 347,
   340, 421, 389, 367, 202, 101, 269, 244, 138, 233,
    294, 31, 179, 144, 474, 34, 110, 201, 89, 120,
    308,36, 229, 242, 139, 258, 23, 74, 376, 197
    , 312, 371, 447, 430, 410, 140, 313, 385, 454, 458
    , 270, 457, 67, 425, 128, 336, 125, 156, 155, 375
    , 213, 470, 117, 193, 352, 488, 232, 212, 63, 408
    , 134, 38, 50, 377, 291, 32, 230, 300, 491, 118
    , 208, 406, 184, 467, 322, 99, 104, 478, 165, 382
    , 92, 146, 204, 364, 469, 116, 8, 178, 324, 328
    , 214, 113, 56, 446, 481, 331, 296, 353};
  /* ,448, 72, 288, 13, 473, 1, 137, 323, 98, 27, 81, 245, 333, 44, 20, 319,
  262, 119, 153, 356, 122, 251, 71, 228, 231, 226, 289, 191, 292, 366, 168, 466
  , 500, 397, 19, 451, 80, 489, 274, 5, 476, 283, 461, 256, 190, 126, 235, 452
  , 198, 151, 112, 236, 426, 334, 88, 100, 223, 222, 209, 171, 196, 28, 440, 94
  , 341, 149, 432, 85, 87, 464, 49, 400, 444, 30, 279, 387, 107, 9, 384, 276
  , 170, 21, 286, 357, 46, 52, 386, 42, 372, 445, 124, 468, 79, 40, 70, 181
  , 315, 350, 186, 311, 264, 284, 60, 106, 449, 327, 431, 97, 83, 174, 318, 441
  , 492, 249, 285, 239, 388, 338, 11, 495, 363, 145, 132, 381, 96, 346, 442, 57
  , 399, 417, 484, 314, 374, 306, 102, 280, 75, 479, 192, 14, 45, 6, 455, 480
  , 55, 423, 167, 37, 131, 143, 332, 398, 54, 130, 335, 378, 164, 411, 309, 438
  , 247, 295, 427, 303, 82, 246, 152, 477, 383, 287, 111, 271, 64, 424, 393, 7
  , 35, 463, 16, 373, 255, 418, 436, 189, 48, 53, 148, 359, 224, 218, 298, 240
  , 227, 320, 163, 17, 487, 391, 173, 496, 305, 297, 68, 422, 362, 401, 290
  , 344, 205, 260, 176, 343, 365, 150, 121, 443, 354, 241, 250, 439, 282, 172
  , 413, 158, 428, 84, 2, 475, 348, 433, 402, 325, 61, 403, 404, 188, 485, 360
  , 453, 41, 248, 415, 216, 58, 392, 321, 133, 154, 253, 136, 22, 437, 259, 369
  , 301, 90, 135, 76, 51, 187, 396, 109, 405, 310, 483, 394, 465, 207, 434, 497
  , 12, 33, 66, 127, 326, 3, 217, 123, 161, 220, 147, 471, 47, 166, 482, 26
  , 261, 266, 407, 456, 24, 337, 472, 175, 4, 254, 494, 429, 234, 160, 272, 194
  , 293, 498, 370, 238, 273, 462, 419, 29, 115, 265, 379, 499, 339, 414, 450
  , 278, 349, 182, 59, 169, 195, 219, 159, 368, 39, 95, 114, 200, 302, 351, 299
  , 65, 203, 395, 141, 142, 77, 221, 390, 15, 225, 199, 267, 412, 86, 420, 206
  , 180, 215, 317, 460, 263, 252, 409, 342, 243, 43, 93, 277, 18, 257, 108, 183
  , 316, 73, 157, 62, 103, 275, 358, 162, 91, 211, 416, 493, 105, 490, 281, 129
  , 329, 78, 355, 330, 435, 307, 210, 268, 177, 459, 25};*/

  (void)argc;
  (void)argv;
  *len = 108;
  input = (int*)malloc(sizeof(int) * (*len));
  i = 0;
  while (i < *len)
  {
    input[i] = tmp[i];
    i++;
  }
  return (input);
}

void env_init(t_env *vn)
{
  vn->a = st_init();
  vn->b = st_init();
  vn->len = 0;
  vn->org = NULL;
  vn->res = NULL;
  vn->ins = NULL;
}

void ft_init_push_swap(t_env *vn, int len)
{
  int i;
  int tmp;

  i = len - 1;
  while (i >= 0)
  {
    tmp = (vn->org)[i];
    st_push(vn->a, tmp);
    i--;
  }
  if (st_is_empty(vn->a))
    ft_ok();
}

void ft_free(t_env **v, t_ps **p)
{
  t_env *vn;
  t_ps *ps;

  vn = *v;
  ps = *p;
  free(vn->org);
  free(vn->res);
  free(vn->cb);
  free(vn->ins);
  free(vn->a);
  free(vn->b);
  free(ps->ins);
  free(*v);
  free(*p);
}

int main(int argc, char *argv[])
{
	t_env *vn;
  t_ps *ps;

  ps = ft_init_ps();
  vn = (t_env*)malloc(sizeof(t_env));
  env_init(vn);
	vn->org = ft_process_input_push_old(argc, argv, &(vn->len));
	ft_assign_res(vn);
	ft_init_push_swap(vn, vn->len);
  push_swap2(vn, ps);
  //printf_ps(vn->a);
  //ft_free(&vn, &ps);
  free(vn);
  free(ps);
  return (0);
}
