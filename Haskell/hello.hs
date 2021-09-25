module Main where

import System.Environment

hello :: String -> String
hello = (++) "Hello, "

main = do
  args <- getArgs
  putStrLn (hello (args !! 0))
