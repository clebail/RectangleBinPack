#include "../MaxRectsBinPack.h"
#include <cstdio>

int showUsage(void)
{
	fprintf(stderr, "Usage: MaxRectsBinPackTest [options] binWidth binHeight w_0 h_0 w_1 h_1 w_2 h_2 ... w_n h_n\n");
	fprintf(stderr, "       options :\n");
	fprintf(stderr, "       -t (default) to print result in text format\n");
	fprintf(stderr, "       -s to print result in svg format\n");
	fprintf(stderr, "       where binWidth and binHeight define the size of the bin.\n");
	fprintf(stderr, "       w_i is the width of the i'th rectangle to pack, and h_i the height.\n");
	fprintf(stderr, "Example: MaxRectsBinPackTest -s 256 256 30 20 50 20 10 80 90 20\n");

	return 0;
}

int main(int argc, char **argv)
{
	using namespace rbp;
	
	// Create a bin to pack to, use the bin size from command line.
	MaxRectsBinPack bin;
	enum { TEXT_MODE, SVG_MODE } mode = TEXT_MODE;
	size_t optind;
	int *rects = (int *)malloc(sizeof(int)*(argc - 1));
	int nb_rect = 0;
    for (optind = 1; optind < argc; optind++)
	{
		if(argv[optind][0] == '-')
		{
			switch(argv[optind][1])
			{
				case 't':
					mode = TEXT_MODE;
					break;
				case 's':
					mode = SVG_MODE;
					break;
				default:
					return showUsage();
			}
		}
		else
		{
			rects[nb_rect] = atoi(argv[optind]);
			nb_rect++;
		}
	}

	if(nb_rect % 2 != 0)
	{
		return showUsage();
	}

	int binWidth = rects[0];
	int binHeight = rects[1];
	if(mode == TEXT_MODE)
		printf("Initializing bin to size %dx%d.\n", binWidth, binHeight);
	else
		printf("<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:svg=\"http://www.w3.org/2000/svg\">\n", binWidth, binHeight);

	bin.Init(binWidth, binHeight);
	
	// Pack each rectangle (w_i, h_i) the user inputted on the command line.
	for(int i = 2; i < nb_rect; i += 2)
	{
		// Read next rectangle to pack.
		int rectWidth = rects[i];
		int rectHeight = rects[i+1];
		if(mode == TEXT_MODE)
			printf("Packing rectangle of size %dx%d: ", rectWidth, rectHeight);

		// Perform the packing.
		MaxRectsBinPack::FreeRectChoiceHeuristic heuristic = MaxRectsBinPack::RectBestShortSideFit; // This can be changed individually even for each rectangle packed.
		Rect packedRect = bin.Insert(rectWidth, rectHeight, heuristic);

		// Test success or failure.
		if (packedRect.height > 0)
			if(mode == TEXT_MODE)
				printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
			else
				printf("<rect style=\"fill:#fab1a0;stroke:#000000;stroke-width:0.234704;stroke-opacity:1\" width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" />\n", packedRect.width, packedRect.height,packedRect.x, packedRect.y);
		else
			fprintf(stderr, "Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
	}
	if(mode == TEXT_MODE)
		printf("Done. All rectangles packed.\n");
	else
		printf("</svg>\n");

	free(rects);
}
