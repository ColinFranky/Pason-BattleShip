


status_t GameBoard::getStatus(int x,int y, int z)
{
	return board[x][y][z];
}

void GameBoard::setStatus(int x, int y, int z, status_t status)
{
	if(board[x][y][z] == UNKNOWN ){
		board[x][y][z] = status;
	}
}