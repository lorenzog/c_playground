int main ( int argc, char **argv ) { 
	int delta = -2;
	int BALLOON_DELTA = 3;

	if ( !( (delta>0) ^ (delta>BALLOON_DELTA)) )
	{
		if ( delta > 0 )
			delta = BALLOON_DELTA;
		else
			delta = -1 * BALLOON_DELTA;
	}

	return delta;
}
