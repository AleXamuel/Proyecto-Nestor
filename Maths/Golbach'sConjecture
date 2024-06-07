
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class GoldbachConjecture {
	static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			n = Integer.parseInt(in.readLine());
			if (n < 2)
				break;
			for (int i = 2; i < n; i++)
				if (isPrime(i))
					if (isPrime(n - i)) {
						System.out.println(n + " = " + i + " + " + (n - i));
						break;
					}

		}

	}

	private static boolean isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		for (int i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		return true;

	}

}
