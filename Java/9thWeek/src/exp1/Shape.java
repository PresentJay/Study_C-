package exp1;
public abstract class Shape
{
	protected int rows;
	protected char character;

	public Shape()
	{
		rows = 0;
		character = ' ';
	}

	public Shape(int x, char ch)
	{
		rows = x;
		character = ch;
	}

	public int getRows()
	{
		return rows;
	}

	public char getCharacter()
	{
		return character;
	}

	public void setRows(int y)
	{
		rows = y;
	}

	public void setCharacter(char ch)
	{
		character = ch;
	}

	public abstract void draw(int x, int y);
}