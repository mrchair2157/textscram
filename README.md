
### Note, this only works on Gnu/Linux. And in theory other Unix like operations systems.
</div>


```c
int main(void)
{

printf("My Textscram program is written in good ol' C.\n");
return 0;

}
```

This program has really one goal, to change around the alphabet in a prearranged manner and undo it.\
Like if I had abc and the user defined way to change it was zfp, abc would be zfp and you could change it back.\

# Let me show you what it does.


![](../../pix/image/textscram1.png)

In this first step I show the contents of the file that I end up converting, titled input.txt

![](../../pix/image/textscram2.png)

<space><space><space><space><space><space>
In this second step I show the prompt and the command I used.
``` 
textscram encode input.txt out.txt en.txt 
``` 
Textscram is the name of the exacutalbe I that run.\ encode is telling the program to use en.txt as a key and turn the letters in to this key's equvalent.
The command goes textscram. 
Encode to make it scrambled decode to unscrable.
input file path. 
  * [ ] output file path.
and the file that has the key.  
the key will be the first 26 chars read from the file.



![](../../pix/image/textscram3.png)

Here I am showing the what happens at the end and that the input file is 702 bytes.\ 
(This program works on larger files but a lot slower)

![](../../pix/image/textscram4.png)

In this image I show that the files have the same number of spacing, capitals, lowercase letters and punctuation.\ 

![](../../pix/image/textscram5.png)

In this last image, I show you the decoding process and the contents of all three files.

# Install [here](https://github.com/mrchair2157/textscram)
``` bash
git clone https://github.com/mrchair2157/textscram
cd textscam
sudo/doas make install
```
that is it.
now you can run the program.

# The end.
