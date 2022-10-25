# Project 2  
Scientific Visualizations  
Charles Ison  
10/20/2022

1. a.) 

$$\nabla f(x, y) = 
\begin{pmatrix}
\frac{\partial f}{\partial x} \\
\frac{\partial f}{\partial y}
\end{pmatrix} =
\begin{pmatrix}
\ 3x^2 - 12xy + 3y^2 - 3 \\
\ -6x^2 + 6xy - 3y^2 + 3
\end{pmatrix}
$$

<br/>

$$\texttt{Get critical points by setting both partial derivates equal to zero and solving: }$$ 

$$ 3(x^2 - 4xy + y^2 - 1) = 0 \texttt{ and } -3(2x^2 - 2xy + y^2 - 1) = 0 $$

<br/>

$$\texttt{Critical Points: }$$

$$ (0, -1), \texttt{ } (0, 1), \texttt{ } (\frac{-2}{\sqrt{13}}, \frac{1}{\sqrt{13}}), \texttt{ } (\frac{2}{\sqrt{13}}, \frac{-1}{\sqrt{13}})$$

1. b.) 

$$H_f = 
\begin{pmatrix}
\frac{\partial^2 z}{\partial x^2} & \frac{\partial^2 z}{\partial x \partial y} \\
\frac{\partial^2 z}{\partial y \partial x} & \frac{\partial^2 z}{\partial y^2}
\end{pmatrix} =
\begin{pmatrix}
\ 6x - 12y & -12x + 6y \\
\ -12x + 6y & 6x - 6y
\end{pmatrix}
$$

<br/>

$$\texttt{For critical point: } (0, -1) \rightarrow 
\begin{pmatrix}
\ 12 & -6 \\
\ -6 & 6
\end{pmatrix}
\rightarrow \lambda	= \frac{18 \pm \sqrt{180}}{2} = 9 \pm 3\sqrt{5} 
$$

$$\texttt{Both eigenvalues are positive, so (0, -1) is a local minimum.}$$

<br/>

$$\texttt{For critical point: } (0, 1) \rightarrow 
\begin{pmatrix}
\ -12 & 6 \\
\ 6 & -6
\end{pmatrix}
\rightarrow \lambda	= \frac{-18 \pm \sqrt{180}}{2} = -9 \pm 3\sqrt{5} 
$$

$$\texttt{Both eigenvalues are negative, so (0, 1) is a local maximum.}$$

<br/>

$$\texttt{For critical point: } (\frac{-2}{\sqrt{13}}, \frac{1}{\sqrt{13}}) \rightarrow 
\begin{pmatrix}
\frac{-24}{\sqrt{13}} & \frac{30}{\sqrt{13}} \\
\frac{30}{\sqrt{13}} & \frac{-18}{\sqrt{13}}
\end{pmatrix}
\rightarrow \lambda = 3(\frac{-7 \pm \sqrt{101}}{\sqrt{13}})
$$

$$\texttt{One eigenvalue is positive and one is negative, so } (\frac{-2}{\sqrt{13}}, \frac{1}{\sqrt{13}}) \texttt{ is a saddle.}$$

<br/>

$$\texttt{For critical point: } (\frac{2}{\sqrt{13}}, \frac{-1}{\sqrt{13}}) \rightarrow 
\begin{pmatrix}
\frac{24}{\sqrt{13}} & \frac{-30}{\sqrt{13}} \\
\frac{-30}{\sqrt{13}} & \frac{18}{\sqrt{13}}
\end{pmatrix}
\rightarrow \lambda = 3(\frac{7 \pm \sqrt{101}}{\sqrt{13}})
$$

$$\texttt{One eigenvalue is positive and one is negative, so } (\frac{2}{\sqrt{13}}, \frac{-1}{\sqrt{13}}) \texttt{ is a saddle.}$$

### Running The Program
* Project was compiled and tested using VisualStudio on the machines in the Kelly computer lab  
* To run part 2.a. use the 'a' button  
* To run part 2.b. use the 'b' button
* To run part 2.c. use the 'c' button
* To run part 2.d use the 'd' button
* To run part 3.a use the 'e' button
* To run part 3.b use the 'f' button

### Critical Point Key
* Red is a minimum
* Blue is a maximum
* Green is a saddle

### R2
* 100 sub intervals
* R2 One Color:

 ![image](r2_one_color.png)

* R2 Multi-Color:

  ![image](r2_multi_color.png)

* R2 Height + One Color:

  ![image](r2_height_one_color.png)  

* R2 Height + Multi-Color:

  ![image](r2_height_multi_color.png) 
  
* R2 Critical Points:

  ![image](r2_critical_points.png)  
  
### R4
* 100 sub intervals

### R9
* 50 sub intervals

### R10
* 50 sub intervals

### R11
* 50 sub intervals

### R12
* 50 sub intervals

### R13
* 50 sub intervals

### R14
* 50 sub intervals
