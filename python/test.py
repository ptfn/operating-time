import unittest
import sum


class CalcTest(unittest.TestCase):
    def test1(self):
        self.assertEqual(sum.sum(2, 3), 5)


if __name__ == '__main__':
    unittest.main()
