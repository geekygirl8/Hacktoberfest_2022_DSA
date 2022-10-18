using System;


// Name: Racer
// Github: https://github.com/ebukaracer

/// <summary>
/// Pascal’s Triangle is an arithmetic and geometric figure first imagined by Blaise Pascal.
/// To build the triangle, start with ”1” at the top,
/// then continue placing numbers below it in a triangular pattern.
/// Each number is the numbers directly above it added together.
/// </summary>
internal class Pascal_Triangle
{
    private static void PascalTriangle(int rowCount = 5)
    {
        for (int row = 1; row <= rowCount; row++)
        {
            int tmp = 1;

            for (int col = 1; col <= row; col++)
            {
                Console.Write($"{tmp} ");

                tmp = tmp * (row - col) / col;
            }

            // Newline, per row.
            Console.WriteLine();
        }
    }
}
