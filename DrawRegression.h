// ---------------------------------------------------------------------------

#ifndef DrawRegressionH
#define DrawRegressionH
#include "MainUnit.h"
#include "FuzzyNumber.h"

// ---------------------------------------------------------------------------
//////////////////////////////////////
// @brief Class with drawning regression methods
class DrawRegression {
private:
	// Graphics::TBitmap plot;

	int h; // plot height
	int w; // plot width
	int line_size;
	double xmax; // maximum x value of model
	double xmin; // minimum x value of model
	double ymax; // maximum y value of model
	double ymin; // minimum y value of model
	double vh; // virtual heigth of plot
	double vw; // virtual width of plot

public:
	//////////////////////////////////////
	// @brief constructor
	// uses xmax, xmin, ymax, ymin, vh, vw
	DrawRegression(int height, int widgth, double xmax, double ymax)
		: h(500), w(500), xmax(10), ymax(10), xmin(0), ymin(0), line_size(5) {
		h = height;
		w = widgth;
		vh = (ymax - ymin);
		vw = (xmax - xmin);
		// pl.Height = h;
		// pl.Width = w;
	}

	//////////////////////////////////////
	// @brief round to tenth
	// s - number for rounding
	double round(double &s) {
		s *= 10;
		s = (s - floor(s) < 0.5) ? floor(s) : ceil(s);
		s /= 10;
		return s;
	}

	//////////////////////////////////////
	// @brief set plot height
	// uses h
	int SetPlotHeight(int height) {
		h = height;
		return 1;
	}

	//////////////////////////////////////
	// @brief set plot width
	// uses w
	int SetPlotWidth(int width) {
		w = width;
		return 1;
	}

	//////////////////////////////////////
	// @brief set plot size
	// uses h, w
	int SetPlotSize(int height, int width) {
		h = height;
		w = width;
		return 1;
	}

	//////////////////////////////////////
	// @brief set line size
	// s - size of line
	int SetLineSize(int s) {
		line_size = s;
		return 1;
	}

	//////////////////////////////////////
	// @brief get virtual coordinates
	// x, y -input coordinates, vx, vy - output coordinates
	// uses xmax, xmin, w, h
	// TO DO: implement
	int GetVirCoord(int x, int y, double &vx, double &vy) {
		return 1;
	}

	//////////////////////////////////////
	// @brief get virtual coordinates
	// x - real pixel position
	// returns virtual x position
	double GetVirX(int x) {
		return x*vw / w;
	}

	//////////////////////////////////////
	// @brief get virtual coordinates
	// y - real pixel position
	// returns virtual y position
	double GetVirY(int y) {
		double mul = y * vh;
		double div = mul / w;
		double ret = h - div;
		return round(ret);
		// return h - y * vh / w;
	}

	//////////////////////////////////////
	// @brief get real coordinates
	// virtx - virtual position
	// returns real x position
	int GetRealX(double virtx) {
		double mul = (double)w * virtx;
		double div = mul / vw;
		int d = round(div);
		return d;
	}

	//////////////////////////////////////
	// @brief get real coordinates
	// virty - virtual position
	// returns real y position
	int GetRealY(double virty) {
		return h - h * virty / vh;
	}

	//////////////////////////////////////
	// @brief get minimum step in virtual coordinates
	double GetStep() {
		return GetVirX(1);
	}

	//////////////////////////////////////
	// @brief draw fuzzy number
	// f - fuzzy number, xpos - independent variable value
	int DrawFuzzyNumber(FuzzyNumber fn, double xpos, TImage* &graph) {
		// graph->Picture = NULL;
		// graph->Width = w;
		// graph->Height = h;
		int realx = GetRealX(xpos);
		int realm = GetRealY(fn.m);
		int reala = GetRealY(fn.m - fn.a);
		int realb = GetRealY(fn.m + fn.b);
		graph->Canvas->Pen->Color = clRed;
		graph->Canvas->MoveTo(realx, realm);
		graph->Canvas->LineTo(realx, realb);
		graph->Canvas->MoveTo(realx, realm);
		graph->Canvas->Pen->Color = clBlue;
		graph->Canvas->LineTo(realx, reala);
		return 1;
	}

};

// ---------------------------------------------------------------------------
#endif
