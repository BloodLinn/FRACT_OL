///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   test.c                                             :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: aokur <aokur@student.42.fr>                +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2025/11/18 16:51:48 by aokur             #+#    #+#             */
///*   Updated: 2025/11/18 17:16:02 by aokur            ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include <stdio.h>

//// 1. Struct Kalıbını Tanımlama
//// 'typedef' sayesinde her seferinde 'struct s_oyuncu' demek yerine
//// sadece 't_oyuncu' diyebileceğiz.
//typedef struct s_araba{
//	char	*marka;
//	int		model;
//	int		fiyat;
//} t_araba;

//static void indirim(t_araba *revizyon1)
//{
//	t_araba düsürme;
//	düsürme.fiyat = 1000000;
//	revizyon1->fiyat = revizyon1->fiyat - (düsürme.fiyat / 10); 
//}

//static void faiz (t_araba *revizyon2)
//{
//	t_araba artma;
//	artma.fiyat = 2000000;
//	revizyon2->fiyat = revizyon2->fiyat + (artma.fiyat / 10);
//}

//int main()
//{
//	t_araba araba1;
//	t_araba araba2;

//	araba1.marka = "mercedes";
//	araba2.marka = "BMW";

//	araba1.model = 2014;
//	araba2.model = 2025;

//	araba1.fiyat = 1000000;
//	araba2.fiyat = 2000000;
	
//	printf("ARABA1 ÖZELLİKLERİ \n Markası: %s \n Modeli: %d \n Fiyatı: %d \n", araba1.marka , araba1.model, araba1.fiyat);
//	printf("ARABA2 ÖZELLİKLERİ \n Markası: %s \n Modeli: %d \n Fiyatı: %d \n ", araba2.marka , araba2.model, araba2.fiyat);
//	indirim(&araba1);
//	printf("ARABA1 İNDİRİMLİ FİYATI: %d \n ", araba1.fiyat);
//	faiz(&araba2);
//	printf("ARABA2 FAİZLİ FİYATI: %d", araba2.fiyat);
//}

//typedef struct s_karakter {
//	int hasar;
//	int can;
//} t_karakter;

//void saldırma(t_karakter *saldiran, t_karakter *savunan)
//{
//	savunan->can = savunan->can - saldiran->hasar;
//}

//void can_yenlieme(t_karakter *canbasan)
//{
//	canbasan->can = canbasan->can + 10;
//}


//int main()
//{
//	t_karakter mario;
//	mario.hasar = 10;
//	mario.can = 100;

//	t_karakter luici;
//	luici.hasar = 60;
//	luici.can = 100;

//	printf("MARIO İLK CAN: %d \n", mario.can);
//	printf("LUİCİ İLK CAN: %d \n", luici.can);

//	saldırma(&mario, &luici);
//	printf("MARİO VURDU LUİCİ SON CAN: %d \n", luici.can);
//	saldırma(&mario, &luici);
//	printf("MARİO VURDU LUİCİ SON CAN: %d \n", luici.can);
//	can_yenlieme(&luici);
//	printf("LUİCİ CAN YENİLEDİ SON CAN: %d \n", luici.can);
//	saldırma(&luici, &mario);
//	printf("LUİCİ VURDU MARIO SON CAN: %d \n", mario.can);
//	can_yenlieme(&mario);
//	printf("MARİO CAN YENİLEDİ SON CAN: %d \n", mario.can);	
//	saldırma(&mario, &luici);
//	printf("MARİO VURDU LUİCİ SON CAN: %d \n", luici.can);
//	saldırma(&mario, &luici);
//	printf("MARİO VURDU LUİCİ SON CAN: %d \n", luici.can);
//	can_yenlieme(&luici);
//	printf("LUİCİ CAN YENİLEDİ SON CAN: %d \n", luici.can);
//	saldırma(&luici, &mario);
//	printf("LUİCİ VURDU MARIO SON CAN: %d \n", mario.can);
//	can_yenlieme(&mario);
//	printf("MARİO CAN YENİLEDİ SON CAN: %d \n", mario.can);
//	if (mario.can <= 0)
//	{
//		printf("MARİO KAYBETTİ, LUİCİ KAZANDI. LUİCİ SON CAN: %d", luici.can);
//		return (0);
//	}
//	if (luici.can <= 0)
//	{
//		printf("LUİCİ KAYBETTİ, MARİO KAZANDI. MARİO SON CAN: %d", luici.can);
//		return (0);
//	}
//}


//void ft_draw_cross(int color, t_fractol *f)
//{
//	int cx = (f->width / 2) - 50;
//	int cy = (f->height / 2) - 50;
//	int bytepp = f->img.bpp / 8;
//	char	*pixel;

//	while(cx <= (f->width / 2) + 50)
//	{
//		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
//		*(unsigned int *)pixel = color;
//		cx++;
//		cy++;
//	}
//	cx = (f->width / 2) + 50;
//	cy = (f->height / 2) - 50;
//	while(cy <= (f->height / 2) + 50)
//	{
//		pixel = f->img.addr + (cy * f->img.line_len) + (cx * bytepp);
//		*(unsigned int *)pixel = color;
//		cx--;
//		cy++;
//	}
//}

//typedef struct s_kolay
//{
//	int cx;
//	int cy;
//	int start_x;
//	int end_x;
//	int start_y;
//	int end_y;
//	char *pixel;
//} t_kolay;

//static void	ft_draw_square_fill(int color, t_fractol *f)
//{
//		t_kolay a;
//		a.cx = f->width / 2;
//		a.cy = f->height / 2;
//		a.start_x = a.cx - 100;
//		a.end_x = a.cx + 100;
//		a.end_y = a.cy + 100;
//		int	bytepp = f->img.bpp / 8;

//		while (a.start_x <= a.end_x)
//		{
//			a.start_y = a.cy - 100;
//			while(a.start_y <= a.end_y)
//			{
//				a.pixel = f->img.addr + (a.start_y * f->img.line_len) + (a.start_x * bytepp);
//				*(unsigned int *)a.pixel = color;
//				a.start_y++;
//			}
//			a.start_x++;
//		}
//}

//void	ft_draw_square_outline(int color, t_fractol *f)
//{
//	t_kolay a;

//	a.cx = f->width / 2;
//	a.cy = f->height / 2;
//	a.start_x = a.cx - 100;
//	a.end_x = a.cx + 100;
//	a.start_y = a.cy - 100;
//	a.end_y = a.cy + 100;
//	int	bytepp = f->img.bpp / 8;

//	while(a.start_x <= a.end_x)
//	{
//		a.pixel = f->img.addr + (a.start_y * f->img.line_len) + (a.start_x * bytepp);
//		*(unsigned int *)a.pixel = color;
//		a.pixel = f->img.addr + (a.end_y * f->img.line_len) + (a.start_x * bytepp);
//		*(unsigned int *)a.pixel = color;
//		a.start_x++;
//	}
//	a.start_x = a.cx - 100;
//	while(a.start_y <= a.end_y)
//	{
//		a.pixel = f->img.addr + (a.start_y * f->img.line_len) + (a.start_x * bytepp);
//		*(unsigned int *)a.pixel = color;
//		a.pixel = f->img.addr + (a.start_y * f->img.line_len) + (a.end_x * bytepp);
//		*(unsigned int *)a.pixel = color;
//		a.start_y++;
//	}
//	int check = 1;
//	if (check == 1)
//		ft_draw_square_fill(0x000000, f);
//}

		//zr_next = zr * zr - zi * zi + re;
		//zi_next = 2 * zr * zi + im;
		//zr = zr_next;
		//zi = zi_next;
		//i++;