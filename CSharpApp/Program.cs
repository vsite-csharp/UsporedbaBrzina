namespace CSharpApp
{
    internal class Program
    {
        static int Loop(int count, bool output)
        {
            var total = 0;

            for (int row = 1; row < count; ++row)
            {
                for (int column = 1; column < count; ++column)
                {
                    total += row + column;
                    if (output)
                    {
                        Console.WriteLine(row * column);
                    }
                }
            }
            return total;
        }

        static void Main(string[] args)
        {
            for (int i = 0; i < 10; ++i)
            {
                var start = DateTime.Now;

                var total = Loop(11, true);

                var end = DateTime.Now;

                var timeDelta = end - start;
                Console.WriteLine($"{i}. C# total: {total}");
                Console.WriteLine($"{i}. C# execution: {timeDelta.TotalMilliseconds * 1000} us");
            }
            
            Console.WriteLine();

            for (int i = 0; i < 10; ++i)
            {
                var start = DateTime.Now;

                var total = Loop(1001, false);

                var end = DateTime.Now;

                var timeDelta = end - start;
                Console.WriteLine($"{i}. C# total: {total}");
                Console.WriteLine($"{i}. C# execution: {timeDelta.TotalMilliseconds * 1000} us");
            }
        }
    }
}