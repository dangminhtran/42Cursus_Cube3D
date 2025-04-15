/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:55:27 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/15 12:19:54 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Recuperer la position du joueur
// Recuperer la direction du joueur
// Recuperer la direction de la camera
// Si le rayon est dans le mur :
    // Calculer la distance entre le joueur et le mur
    // Calculer la hauteur de la ligne a dessiner
    // Dessiner la ligne
// Si le rayon n'est pas dans le mur :
    // Dessiner le sol et le plafond


// Comment savoir si le rayon frappe le mur ?
    // Checker plusieurs points
    // On peut prendre chaque cote du carre

    // TODO - Algorithme DDA ?
    // TODO - Euclidean angles ?
    
    /* TODO - Vecteurs & camera ?
    - la position du player : x -> y - parallele a la camera plane
    - la direction du player : x -> y
    - la direction de la camera plane : doit etre perpendiculaire a la direction du rayon
    
    
    calcul de la ligne ?
    
    si on multiplie x et y par la meme valeur,
    ca change la longueur et garde la meme direction

    Calculer les distances : prendre la width de l'ecran / de la map
    - Verifier si le point de vue est plus court ou plus long ? 
    */